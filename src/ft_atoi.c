/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:14 by theo              #+#    #+#             */
/*   Updated: 2022/09/11 19:44:30 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static	int	ft_isws(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			is_neg;
	long long	total;

	i = 0;
	while (ft_isws(nptr[i]))
		i++;
	is_neg = 0;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		is_neg = (nptr[i] == '-');
		i += 1;
	}
	total = 0;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (total);
		if (is_neg)
			total = total * 10 - (nptr[i] - '0');
		else
			total = total * 10 + (nptr[i] - '0');
		i++;
	}
	return (total);
}
