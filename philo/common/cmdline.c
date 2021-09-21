/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:43:45 by graja             #+#    #+#             */
/*   Updated: 2021/09/21 15:48:56 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_cmdline(int argc, char **argv)
{
	if ((argc < 5) || (argc > 6))
		return (0);
	printf(" %d, %d", ft_atoi(argv[1]), ft_atoi(argv[2]));
	printf(", %d, %d", ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
		printf(", %d\n", ft_atoi(argv[5]));
	else
		printf("\n");
	return (1);
}
