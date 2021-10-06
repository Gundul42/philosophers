/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:22:11 by graja             #+#    #+#             */
/*   Updated: 2021/10/02 13:34:11 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static
void	take_forks(t_philo *data)
{
	if (!data->act && data->myfork == 0 && *data->yourfork == 0)
	{
		pthread_mutex_lock(&data->fork);
		data->myfork = data->nbr;
		pthread_mutex_unlock(&data->fork);
		pthread_mutex_lock(data->death);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d has taken a fork\n", data->nbr);
		pthread_mutex_unlock(data->death);
		pthread_mutex_lock(data->nfork);
		*data->yourfork = data->nbr;
		pthread_mutex_unlock(data->nfork);
		pthread_mutex_lock(data->death);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d has taken a fork\n", data->nbr);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d is eating\n", data->nbr);
		pthread_mutex_unlock(data->death);
		data->lstact = get_time_milli();
		data->lstmeal = data->lstact;
		data->act = 1;
	}
}

static
void	eat_meal(t_philo *data)
{
	if (data->act == 1 && get_time_milli() - data->lstact >= data->tteat)
	{
		pthread_mutex_lock(&data->fork);
		data->myfork = 0;
		pthread_mutex_unlock(&data->fork);
		pthread_mutex_lock(data->nfork);
		*data->yourfork = 0;
		pthread_mutex_unlock(data->nfork);
		if (data->meals > 0)
			data->meals--;
		pthread_mutex_lock(data->death);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d is sleeping\n", data->nbr);
		pthread_mutex_unlock(data->death);
		data->act = 2;
		data->lstact = get_time_milli();
	}
}

static
void	ft_sleep(t_philo *data)
{
	if (data->act == 2 && get_time_milli() - data->lstact >= data->ttslp)
	{
		pthread_mutex_lock(data->death);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d is thinking\n", data->nbr);
		pthread_mutex_unlock(data->death);
		data->act = 0;
		data->lstact = get_time_milli();
	}
}

static
int	check_death(t_philo *data)
{
	long	ttime;

	if (*data->rip)
		return (1);
	usleep(50);
	ttime = get_time_milli() - data->lstmeal;
	if (!*data->rip && ttime > data->ttdie)
	{
		pthread_mutex_lock(data->access);
		*data->rip = 1;
		pthread_mutex_unlock(data->access);
		pthread_mutex_lock(data->death);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d died\n", data->nbr);
		pthread_mutex_unlock(data->death);
		return (1);
	}
	return (0);
}

void	*run_philos(void *ptr)
{
	t_philo	*data;

	data = (t_philo *)(ptr);
	while (data->meals != 0 && !check_death(data))
	{
		take_forks(data);
		eat_meal(data);
		ft_sleep(data);
		if (data->meals == 0)
		{
			pthread_mutex_lock(data->death);
			printf("%010ld", get_time_milli() - data->timestamp);
			printf(" %3d had all meals\n", data->nbr);
			pthread_mutex_unlock(data->death);
		}
		usleep(20);
	}
	return (NULL);
}
