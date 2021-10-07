/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:14:07 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 13:20:32 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	printit(t_philo *data, char *str)
{
	if (!*data->rip)
	{
		pthread_mutex_lock(data->death);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d %s\n", data->nbr, str);
		pthread_mutex_unlock(data->death);
	}
}
