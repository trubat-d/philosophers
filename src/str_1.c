/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:14 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:15 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo philo, struct timeval time, struct timeval start)
{
	if (philo.is_dead)
		return ;
	gettimeofday(&time, NULL);
	if (philo.state == thinking)
		printf("%ld %d is thinking\n", time_to_mil(time) - \
		time_to_mil(start), philo.id);
	else if (philo.state == taking_fork)
		printf("%ld %d has taken a fork\n", time_to_mil(time) - \
		time_to_mil(start), philo.id);
	else if (philo.state == sleeping)
		printf("%ld %d is sleeping\n", time_to_mil(time) - \
		time_to_mil(start), philo.id);
	else if (philo.state == dead)
		printf("%ld %d died\n", time_to_mil(time) - \
		time_to_mil(start), philo.id);
	else if (philo.state == eating)
		printf("%ld %d is eating\n", time_to_mil(time) - \
		time_to_mil(start), philo.id);
}
