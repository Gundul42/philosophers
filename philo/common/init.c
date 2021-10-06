/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:35:12 by graja             #+#    #+#             */
/*   Updated: 2021/10/02 13:43:09 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static
pthread_mutex_t	*init_mutex(void)
{
	pthread_mutex_t	*ptr;

	ptr = calloc(1, sizeof(pthread_mutex_t));
	if ((!ptr) || (pthread_mutex_init(ptr, NULL)))
		return (NULL);
	return (ptr);
}

static
int	set_args(int i, int argc, char **argv, t_philo *data)
{
	data[i].nbr = i + 1;
	data[i].ttl = ft_atoi(argv[1]);
	data[i].ttdie = ft_atoi(argv[2]);
	data[i].tteat = ft_atoi(argv[3]);
	data[i].ttslp = ft_atoi(argv[4]);
	if (argc == 6)
		data[i].meals = ft_atoi(argv[5]);
	else
		data[i].meals = -1;
	i++;
	return (i);
}

static
void	set_ptrs(t_philo *data, int i, int j)
{
	data[i].nfork = &data[j - 1].fork;
	data[i].yourfork = &data[j - 1].myfork;
	if (!i && data[i].ttl == 1)
		data[i].myfork = -1;
}

int	init_philo(int argc, char **argv, t_philo *data)
{
	pthread_mutex_t	*death;
	pthread_mutex_t	*access;
	int				*rip;
	int				i;

	i = 0;
	death = init_mutex();
	access = init_mutex();
	rip = calloc(1, sizeof(int));
	if (!rip || !death || !access)
		return (1);
	while (i < ft_atoi(argv[1]))
	{
		if (i)
			set_ptrs(data, i, i);
		if (pthread_mutex_init(&data[i].fork, NULL))
			return (1);
		data[i].death = death;
		data[i].access = access;
		data[i].rip = rip;
		i = set_args(i, argc, argv, data);
	}
	set_ptrs(data, 0, i);
	return (0);
}
