/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:24:11 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 10:02:48 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	cleanup(t_philo *data)
{
	if (data)
	{
		sem_unlink("/forks");
		sem_unlink("/death");
		sem_unlink("/access");
		sem_close(data->forks);
		sem_close(data->death);
		sem_close(data->access);
		free(data);
	}
}

void	killemall(t_philo *data, int *lst)
{
	int	i;

	i = 0;
	while (i < data->ttl)
	{
		if (lst[i])
			kill(lst[i], SIGKILL);
		i++;
	}
}

int	error_print(char *s, t_philo *data)
{
	printf(">>> Error in %s <<<\n\n", s);
	if (data)
		cleanup(data);
	return (1);
}
