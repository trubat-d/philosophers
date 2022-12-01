/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:16 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:25 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*def_mutex_gen(void)
{
	pthread_mutex_t	*res;

	res = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(res, NULL))
		return (NULL);
	return (res);
}

int	start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_ph)
	{
		pthread_create(&data->philos[i]->instance, NULL, &routine, \
		data->philos[i]);
		i++;
	}
	return (0);
}

int	thread_end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_ph)
	{
		pthread_join(data->philos[i]->instance, NULL);
		i++;
	}
	i = 0;
	while (i < data->num_ph)
	{
		pthread_mutex_destroy(data->philos[i]->ph_fork);
		i++;
	}
	return (0);
}
