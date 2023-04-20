/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:27:14 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/20 13:25:58 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	long			time_eat;
	long			time_sleep;
	long			time_think;
	long			how_many_eat;
	pthread_t		thread;
}	t_philo;

typedef struct s_philo_struct
{
	long			nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			how_many_eat;
	pthread_mutex_t	*forks;
	t_philo			*philosophers;
}	t_philo_struct;

int		all_argv_int(char **argv, int argc);
int		validate_int(t_philo_struct *philo_struct);
long	ft_atoi(const char *str);
#endif