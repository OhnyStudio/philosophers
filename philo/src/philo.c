/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:53:51 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/19 12:25:32 by jsavard          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_philo_struct	philo_struct;

	if ((argc < 5 || argc > 6) || all_argv_int(argv, argc) == 0)
		printf("Mauvais parametres !");
	else
	{
		set_data(&philo_struct, argv, argc);
		if (validate_int(&philo_struct) != 0)
		{
			//Do thing
		}
	}
	return (0);
}
