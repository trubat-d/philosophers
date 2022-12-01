/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:17:23 by trubat-d          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:23 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	mic_mil_sec(long time)
{
	return (time / (long)1000);
}

long	sec_mil_mic(long time)
{
	return (time * 1000);
}

long long	sec_to_mic(long sec)
{
	return (sec * 1000000);
}

long	time_to_mil(struct timeval time)
{
	return (sec_mil_mic(time.tv_sec) + mic_mil_sec(time.tv_usec));
}
