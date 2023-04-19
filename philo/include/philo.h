/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:27:14 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/19 12:22:17 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "stdio.h"

typedef struct s_philo_struct
{
	long	nb_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	how_many_eat;
}	t_philo_struct;

int		all_argv_int(char **argv, int argc);
int		validate_int(t_philo_struct *philo_struct);
long	ft_atoi(const char *str);
#endif