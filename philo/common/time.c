/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:18:58 by graja             #+#    #+#             */
/*   Updated: 2021/09/22 11:50:17 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

long	get_time_milli(void)
{
	long	ret;
	struct timeval	tv;

	usleep(20);
	if (gettimeofday(&tv, NULL) < 0)
		return (-1);
	ret = (long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (ret);
}
