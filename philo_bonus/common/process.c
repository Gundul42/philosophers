/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:22:11 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 15:50:06 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static
void	start_eat(t_philo *data)
{
	sem_wait(data->access);
	printf("%010ld", get_time_milli() - data->timestamp);
	printf(" %3d is eating\n", data->nbr);
	sem_post(data->access);
	data->lstact = get_time_milli();
	data->lstmeal = data->lstact;
	data->act = 1;
}

static
void	take_forks(t_philo *data)
{
	if (!data->act && data->tools <= 2 && data->ttl > 1)
	{
		if (data->tools < 2)
		{
			sem_wait(data->forks);
			usleep(50);
			sem_wait(data->forks);
			sem_wait(data->access);
			printf("%010ld", get_time_milli() - data->timestamp);
			printf(" %3d has taken a fork\n", data->nbr);
			printf("%010ld", get_time_milli() - data->timestamp);
			printf(" %3d has taken a fork\n", data->nbr);
			sem_post(data->access);
			data->tools += 2;
		}
		else if (data->tools == 2)
			start_eat(data);
	}
}

static
void	ft_sleep(t_philo *data)
{
	if (data->act == 2 && get_time_milli() - data->lstact >= data->ttslp)
	{
		sem_wait(data->access);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d is thinking\n", data->nbr);
		sem_post(data->access);
		data->act = 0;
		data->lstact = get_time_milli();
	}
}

int	run_philos(t_philo *data)
{
	while (data->meals != 0 && !check_death(data))
	{
		take_forks(data);
		eat_meal(data);
		ft_sleep(data);
		if (data->meals == 0)
		{
			sem_wait(data->access);
			printf("%010ld", get_time_milli() - data->timestamp);
			printf(" \033[0;33m%3d had all meals\x1b[0m\n", data->nbr);
			sem_post(data->access);
		}
		usleep(20);
	}
	if (data->act == 666)
		return (1);
	return (0);
}
