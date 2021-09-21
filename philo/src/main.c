/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:36:47 by graja             #+#    #+#             */
/*   Updated: 2021/09/21 17:51:38 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	suseconds_t	tme;

	if (!check_cmdline(argc, argv))
		return (EXIT_FAILURE);
	while (tme >= 0)
	{
		printf("%10ld\n", tme);
		/*usleep(10);*/
		tme = get_time_milli();
	}
	return (EXIT_SUCCESS);
}
