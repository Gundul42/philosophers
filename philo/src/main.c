/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:36:47 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 16:20:43 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	letsgo(t_philo *data)
{
	int		i;
	long	tme;

	i = 0;
	tme = get_time_milli();
	while (i < data[i].ttl)
	{
		data[i].timestamp = tme;
		data[i].lstmeal = data[i].timestamp;
		if (pthread_create(&data[i].id, NULL, run_philos, &data[i]))
			return (1);
		usleep(20);
		i++;
	}
	while (i > 0)
	{
		pthread_join(data[i - 1].id, NULL);
		i--;
	}
	return (0);
}

static
int	error_print(char *s, t_philo *data)
{
	printf(">>> Error in %s <<<\n\n", s);
	if (data)
		cleanup(data);
	return (1);
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
		data = calloc(ft_atoi(argv[1]), sizeof(t_philo));
	if (!err && !data)
		err = error_print("memory allocation", data);
	if (!err && init_philo(argc, argv, data))
		err = error_print("mutex creation", data);
	if (!err && letsgo(data))
		err = error_print("memory allocation", data);
	if (data)
		cleanup(data);
	if (err)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
