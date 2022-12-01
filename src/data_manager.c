/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:16:49 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:16:50 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_philo_tab(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < data->num_ph)
	{
		data->philos[i] = gen_philo(i);
		if (!data->philos[i])
			return (1);
		data->philos[i]->ttd = ft_atoi(av[2]);
		data->philos[i]->tte = ft_atoi(av[3]);
		data->philos[i]->tts = ft_atoi(av[4]);
		data->philos[i]->last_eat = 0;
		data->philos[i]->eats = 0;
		data->philos[i]->end = 0;
		data->philos[i]->start_condition = 0;
		data->philos[i]->is_dead = 0;
		if (ac == 6)
			data->philos[i]->max_eat = ft_atoi(av[5]);
		else
			data->philos[i]->max_eat = -1;
		i++;
	}
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	if (ft_atoi(av[1]) <= 0)
		return (1);
	data->num_ph = ft_atoi(av[1]);
	data->philos = malloc(sizeof(t_philo) * data->num_ph);
	if (fill_philo_tab(data, ac, av))
		return (1);
	assign_fork(data);
	return (0);
}
