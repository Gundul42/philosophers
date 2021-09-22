/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:36:47 by graja             #+#    #+#             */
/*   Updated: 2021/09/22 11:51:20 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	long	tme;

	tme = 0;
	if (!check_cmdline(argc, argv))
		return (EXIT_FAILURE);
	while (tme >= 0)
	{
		printf("%14ld\n", tme);
		tme = get_time_milli();
	}
	return (EXIT_SUCCESS);
}
