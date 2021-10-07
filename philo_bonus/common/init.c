/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:35:12 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 15:45:30 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	set_sems(t_philo *data)
{
	sem_unlink("/forks");
	sem_unlink("/death");
	sem_unlink("/access");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->ttl);
	data->death = sem_open("/death", O_CREAT, 0644, 1);
	data->access = sem_open("/access", O_CREAT, 0644, 1);
}

int	init_philo(int argc, char **argv, t_philo *data)
{
	data->ttl = ft_atoi(argv[1]);
	data->ttdie = ft_atoi(argv[2]);
	data->tteat = ft_atoi(argv[3]);
	data->ttslp = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals = ft_atoi(argv[5]);
	else
		data->meals = -1;
	set_sems(data);
	if (data->forks == SEM_FAILED || data->death == SEM_FAILED
		|| data->access == SEM_FAILED)
		return (1);
	return (0);
}
