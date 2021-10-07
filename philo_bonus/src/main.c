/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:36:47 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 16:21:31 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static
void	wait_for_end(t_philo *data, int *lst, int status, int i)
{
	while (!status && i > 0)
	{
		waitpid(-1, &status, 0);
		i--;
	}
	if (status == 65280)
		killemall(data, lst);
	free(lst);
}

static
int	letsgo(t_philo *data, int n)
{
	pid_t	*lst;
	int		i;
	int		status;

	status = 0;
	lst = malloc(sizeof(pid_t) * n);
	i = 0;
	while (i < n)
	{
		data->nbr = i + 1;
		data->timestamp = get_time_milli();
		data->lstmeal = data->timestamp;
		lst[i] = fork();
		usleep(20);
		if (!lst[i])
		{
			if (!run_philos(data))
				exit (0);
			else
				exit (-1);
		}
		i++;
	}
	wait_for_end(data, lst, status, i);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*data;
	int		err;

	err = 0;
	data = NULL;
	if (!check_cmdline(argc, argv))
		err = error_print("parameters: [1-200][>=60][>=60][>=60]{>=1}",
				data);
	if (!err)
		data = calloc(1, sizeof(t_philo));
	if (!err && !data)
		err = error_print("memory allocation", data);
	if (!err && init_philo(argc, argv, data))
		err = error_print("semaphore creation", data);
	if (!err && letsgo(data, ft_atoi(argv[1])))
		err = error_print("memory allocation", data);
	if (data)
		cleanup(data);
	if (err)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
