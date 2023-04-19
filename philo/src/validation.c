/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:38:57 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/19 12:03:46 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static long	ft_check_max(unsigned long long nb, int signe)
{
	if (nb > 9223372036854775807)
	{
		if (signe < 0)
			return (0);
		else
			return (-1);
	}
	return (nb * signe);
}

long	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (ft_check_max(nb, signe));
}

static int	is_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	all_argv_int(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_int(argv[i]) != 1)
			return (0);
		i++;
	}
	if (i < 5)
		return (0);
	return (1);
}
