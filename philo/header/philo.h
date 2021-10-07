/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:31:42 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 14:13:14 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo {
	int				nbr;
	pthread_t		id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*nfork;
	pthread_mutex_t	*death;
	pthread_mutex_t	*access;
	int				ttl;
	int				ttdie;
	int				tteat;
	int				ttslp;
	int				meals;
	int				act;
	int				myfork;
	int				*yourfork;
	int				*rip;
	long			timestamp;
	long			lstmeal;
	long			lstact;
}		t_philo;

int		check_cmdline(int argc, char **argv);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		init_philo(int argc, char **argv, t_philo *data);
int		letsgo(t_philo *data);
void	printit(t_philo *data, char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*run_philos(void *ptr);
void	cleanup(t_philo *data);
long	get_time_milli(void);
size_t	ft_strlen(const char *s);

#endif
