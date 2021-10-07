/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:31:42 by graja             #+#    #+#             */
/*   Updated: 2021/10/06 15:58:46 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_philo {
	sem_t	*forks;
	sem_t	*death;
	sem_t	*access;
	int		nbr;
	int		ttl;
	int		ttdie;
	int		tteat;
	int		ttslp;
	int		meals;
	int		act;
	int		tools;
	int		*rip;
	long	timestamp;
	long	lstmeal;
	long	lstact;
}		t_philo;

int		check_cmdline(int argc, char **argv);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		init_philo(int argc, char **argv, t_philo *data);
int		error_print(char *s, t_philo *data);
int		run_philos(t_philo *data);
int		check_death(t_philo *data);
void	set_sems(t_philo *data);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	cleanup(t_philo *data);
void	killemall(t_philo *data, int *lst);
void	eat_meal(t_philo *data);
long	get_time_milli(void);
size_t	ft_strlen(const char *s);

#endif
