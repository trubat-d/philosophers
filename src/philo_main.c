/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:02 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:03 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_death(t_data *data)
{
	int				i;
	int				is_end;
	struct timeval	time;

	usleep(1000);
	while (1)
	{
		i = -1;
		is_end = 0;
		while (++i < data->num_ph)
		{
			is_end = !data->philos[i]->end;
			gettimeofday(&time, NULL);
			data->philos[i]->cur_time = time_to_mil(time);
			if (data->philos[i]->cur_time - data->philos[i]->last_eat \
			> (unsigned long long ) data->philos[i]->ttd)
			{
				print_death(data->philos[i], data);
				return ;
			}
		}
		if (is_end == 0)
			return ;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (arg_check(ac, av))
			return (0);
		init_data(&data, ac, av);
		start_threads(&data);
		philo_death(&data);
		thread_end(&data);
		free_data(&data);
	}
	else
		printf("Invalid number of arguments!");
	return (0);
}
