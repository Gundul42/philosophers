/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:43:45 by graja             #+#    #+#             */
/*   Updated: 2021/10/02 09:36:20 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static
int	check_numbers(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (0);
	if (ft_atoi(argv[2]) < 60)
		return (0);
	if (ft_atoi(argv[3]) < 60)
		return (0);
	if (ft_atoi(argv[4]) < 60)
		return (0);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (0);
	return (1);
}

int	check_cmdline(int argc, char **argv)
{
	char	*str;
	int		i;

	if ((argc < 5) || (argc > 6))
		return (0);
	i = 2;
	while (i <= argc)
	{
		str = argv[i - 1];
		if (ft_strlen(str) > 10)
			return (0);
		while (*str)
		{
			if (*str != '-' && *str != '+' && !ft_isdigit(*str))
				return (0);
			str++;
		}
		i++;
	}
	return (check_numbers(argc, argv));
}
