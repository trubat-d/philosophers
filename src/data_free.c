/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:16:45 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:16:47 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_ph)
	{
		free(data->philos[i]->ph_fork);
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
	return (0);
}
