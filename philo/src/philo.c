/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:53:51 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/20 13:25:16 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_data(t_philo_struct *philo_struct, char **argv, int argc)
{
	philo_struct->nb_philo = ft_atoi(argv[1]);
	philo_struct->time_to_die = ft_atoi(argv[2]);
	philo_struct->time_to_eat = ft_atoi(argv[3]);
	philo_struct->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_struct->how_many_eat = ft_atoi(argv[5]);
	else
		philo_struct->how_many_eat = -1;
}

static void	*routine_pair()
{
	//sleep for X time
	//Than manger X Time
	return (0);
}

static void	*routine_inpair()
{
	//Manger for X time
	//Than sleep X time
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo_struct	philo_struct;
	int				i;

	if ((argc < 5 || argc > 6) || all_argv_int(argv, argc) == 0)
		printf("Mauvais parametres !");
	else
	{
		set_data(&philo_struct, argv, argc);
		if (validate_int(&philo_struct) != 0)
		{
			i = 0;
			philo_struct.philosophers = (t_philo *)malloc(sizeof(t_philo)
					* philo_struct.nb_philo);
			philo_struct.forks = (pthread_mutex_t *)malloc(sizeof
					(pthread_mutex_t) * philo_struct.nb_philo);
			while (i < philo_struct.nb_philo)
			{
				pthread_mutex_init(&philo_struct.forks[i], NULL);
				if (i % 2 == 0)
				{
					if (pthread_create(&philo_struct.philosophers->thread[i],
							NULL, &routine_pair, NULL) != 0)
						return (1);
				}
				else
				{
					if (pthread_create(&philo_struct.philosophers->thread[i],
							NULL, &routine_inpair, NULL) != 0)
						return (1);
				}
				i++;
			}
			i = 0;
			while (i < philo_struct.nb_philo)
			{
				if (pthread_join(&philo_struct.philosophers->thread[i],
						NULL) != 0)
					return (2);
				pthread_mutex_destroy(&philo_struct.forks[i]);
				i++;
			}
		}
	}
	return (0);
}
