/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:24:11 by graja             #+#    #+#             */
/*   Updated: 2021/10/02 12:38:44 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	cleanup(t_philo *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(data[i].death);
	pthread_mutex_destroy(data[i].access);
	if (data->death)
		free(data[i].death);
	if (data->access)
		free(data[i].access);
	if (data->rip)
		free(data[i].rip);
	while (i < data->ttl)
	{
		pthread_mutex_destroy(&data[i].fork);
		i++;
	}
	free(data);
}
