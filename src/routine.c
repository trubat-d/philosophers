/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:10 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:26 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(t_philo *philo, t_data *data)
{
	struct timeval	time;
	int				j;

	gettimeofday(&time, NULL);
	philo->cur_time = time_to_mil(time);
	printf("%llu %d died\n", philo->cur_time - philo->start_time, philo->id);
	j = 0;
	while (j < data->num_ph)
	{
		data->philos[j++]->is_dead = 1;
	}
}

void	update_time(struct timeval *time, struct timeval *start, \
struct timeval *check, t_philo *philo)
{
	gettimeofday(start, NULL);
	gettimeofday(time, NULL);
	gettimeofday(check, NULL);
	philo->start_time = time_to_mil(*start);
	philo->cur_time = time_to_mil(*time);
	philo->last_eat = time_to_mil(*check);
}

int	check_start(t_philo *phil, struct timeval *time, struct timeval *start)
{
	if (phil->is_dead)
		return (1);
	print_state(*phil, *time, *start);
	if (phil->id % 2 == 1 && phil->start_condition == 0)
	{
		sleeper(5, phil);
		phil->start_condition = 1;
	}
	if (!phil->next_fork)
	{
		sleeper(phil->ttd, phil);
		return (1);
	}
	return (0);
}

int	eater(t_philo *phil, struct timeval *time, \
struct timeval *start, struct timeval *check)
{
	if (phil->is_dead)
		return (1);
	mlock(phil);
	phil->state = taking_fork;
	phil->eats += 1;
	if (phil->is_dead)
		return (1);
	print_state(*phil, *time, *start);
	sleeper(phil->tte, phil);
	munlock(phil);
	gettimeofday(check, NULL);
	phil->last_eat = time_to_mil(*check);
	return (0);
}

void	*routine(void *philo)
{
	int				i;
	t_philo			*phil;
	struct timeval	time;
	struct timeval	start;
	struct timeval	check;

	i = 0;
	phil = (t_philo *)philo;
	update_time(&time, &start, &check, phil);
	while (!phil->is_dead && \
	(phil->max_eat == -1 || phil->eats < phil->max_eat))
	{
		if (check_start(phil, &time, &start) || \
		eater(phil, &time, &start, &check))
			break ;
		phil->state = sleeping;
		if (phil->is_dead)
			break ;
		print_state(*phil, time, start);
		sleeper(phil->tts, phil);
		phil->state = thinking;
		i++;
	}
	phil->end = 1;
	return (NULL);
}
