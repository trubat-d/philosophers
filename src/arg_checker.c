/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:16:38 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:16:39 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_check(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_type(av[i]) || check_limit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_limit(char *arg)
{
	long long	num;

	num = ft_atoi(arg);
	if (num > INT_MAX)
	{
		printf("Argument is invalid: Over INT_MAX\n");
		return (1);
	}
	if (num < 0)
	{
		printf("Argument is invalid: Negative\n");
		return (1);
	}
	if (num == 0)
	{
		printf("Argument is invalid: Zero\n");
		return (1);
	}
	return (0);
}

int	check_type(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9') && arg[i] != '-')
		{
			printf("Argument [%s] is invalid, not a number", arg);
			return (1);
		}
		i++;
	}
	return (0);
}
