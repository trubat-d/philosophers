/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:18 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:24 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeper(int milisec, t_philo *philo)
{
	struct timeval	time;
	struct timeval	cur;
	long long		microstrt;
	long long		microcur;

	gettimeofday(&time, NULL);
	microstrt = sec_to_mic(time.tv_sec) + time.tv_usec;
	gettimeofday(&cur, NULL);
	microcur = sec_to_mic(cur.tv_sec) + cur.tv_usec;
	while (mic_mil_sec(microcur - microstrt) < milisec)
	{
		if (philo->is_dead)
			break ;
		usleep(10);
		gettimeofday(&cur, NULL);
		microcur = sec_to_mic(cur.tv_sec) + cur.tv_usec;
		philo->cur_time = time_to_mil(cur);
	}
	gettimeofday(&time, NULL);
	philo->cur_time = time_to_mil(time);
	return (0);
}

void	mlock(t_philo *philo)
{
	pthread_mutex_lock(philo->ph_fork);
	pthread_mutex_lock(philo->next_fork);
}

void	munlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->ph_fork);
	pthread_mutex_unlock(philo->next_fork);
}
