/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:22:11 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 16:43:53 by graja            ###   ########.fr       */
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
		printit(data, "has taken a fork");
		pthread_mutex_lock(data->nfork);
		*data->yourfork = data->nbr;
		pthread_mutex_unlock(data->nfork);
		printit(data, "has taken a fork");
		printit(data, "is eating");
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
		printit(data, "is sleeping");
		data->act = 2;
		data->lstact = get_time_milli();
	}
}

static
void	ft_sleep(t_philo *data)
{
	if (data->act == 2 && get_time_milli() - data->lstact >= data->ttslp)
	{
		printit(data, "is thinking");
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
	ttime = get_time_milli() - data->lstmeal;
	if (!*data->rip && ttime > data->ttdie)
	{
		pthread_mutex_lock(data->access);
		*data->rip = 1;
		pthread_mutex_lock(data->death);
		printf("%010ld", get_time_milli() - data->timestamp);
		printf(" %3d died\n", data->nbr);
		pthread_mutex_unlock(data->death);
		usleep(50);
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
		pthread_mutex_unlock(data->access);
		take_forks(data);
		eat_meal(data);
		ft_sleep(data);
		if (data->meals == 0)
		{
			pthread_mutex_lock(data->death);
			printf("%010ld", get_time_milli() - data->timestamp);
			printf(" \033[0;33m%3d had all meals\x1b[0m\n", data->nbr);
			pthread_mutex_unlock(data->death);
		}
		usleep(50);
	}
	return (NULL);
}
