/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:18:58 by graja             #+#    #+#             */
/*   Updated: 2021/09/21 18:08:28 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

suseconds_t	get_time_milli(void)
{
	struct timeval	*tv;
	struct timezone	*tz;
	suseconds_t	ret;

	usleep(20);
	tv = malloc(sizeof(struct timeval));
	tz = malloc(sizeof(struct timezone));
	if (!tv || !tz || gettimeofday(tv, tz) < 0)
		return (-1);
	ret = (tv->tv_sec + tv->tv_usec) / 1000;
	free(tv);
	free(tz);
	return (ret);
}
