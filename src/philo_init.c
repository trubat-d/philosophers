/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:16:59 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:16:59 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assign_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_ph)
	{
		if (i < (data->num_ph - 1))
		{
			data->philos[i]->next_fork = data->philos[i + 1]->ph_fork;
		}
		else if (i == (data->num_ph - 1) && i >= 1)
		{
			data->philos[i]->next_fork = data->philos[0]->ph_fork;
		}
		i++;
	}
	return (0);
}

t_philo	*gen_philo(int i)
{
	t_philo	*phil;

	phil = malloc(sizeof(t_philo));
	phil->id = i + 1;
	phil->state = thinking;
	phil->ph_fork = def_mutex_gen();
	phil->next_fork = NULL;
	return (phil);
}
