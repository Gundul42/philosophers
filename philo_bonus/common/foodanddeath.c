/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foodanddeath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:18:08 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 11:22:14 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat_meal(t_philo *data)
{
	if (data->act == 1 && get_time_milli() - data->lstact >= data->tteat)
	{
		sem_post(data->forks);
		usleep(50);
		sem_post(data->forks);
		data->tools -= 2;
		if (data->meals > 0)
			data->meals--;
		sem_wait(data->access);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d is sleeping\n", data->nbr);
		sem_post(data->access);
		data->act = 2;
		data->lstact = get_time_milli();
	}
}

int	check_death(t_philo *data)
{
	long	ttime;

	ttime = get_time_milli() - data->lstmeal;
	if (ttime > data->ttdie)
	{
		sem_wait(data->death);
		data->act = 666;
		usleep(20);
		sem_post(data->death);
		sem_wait(data->access);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d died\n", data->nbr);
		return (1);
	}
	return (0);
}
