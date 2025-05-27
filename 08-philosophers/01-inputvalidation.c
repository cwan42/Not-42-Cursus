/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-inputvalidation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:53:46 by cwan              #+#    #+#             */
/*   Updated: 2024/10/13 10:33:10 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errormessage(int code)
{
	if (code == 1)
	{
		printf(P"Wrong no. of arguments. Run with 4 or 5 values:\n"OG);
		printf(P2"No. of philosphers,"OG);
		printf(P2" time to die, eat, sleep in seconds\n"OG);
		printf(P3"Optional: number of meals to eat\n"OG);
	}
	if (code == 2)
		printf(P4"Wrong syntax, values must be positive integers\n"OG);
	exit (1);
}

int	maxmincheck(char **av)
{
	av++;
	if (ft_atoi(*av) < 1 || ft_atoi(*av) > 200)
		return (printf(P"No. of philosophers must be between 1 to 200\n"OG), 1);
	av++;
	if (ft_atoi(*av) < 1 || ft_atoi(*av) > 200)
		return (printf(P2"Time to die must be between 1 to 200\n"OG), 1);
	av++;
	if (ft_atoi(*av) < 1 || ft_atoi(*av) > 200)
		return (printf(P3"Time to eat must be between 1 to 200\n"OG), 1);
	av++;
	if (ft_atoi(*av) < 1 || ft_atoi(*av) > 200)
		return (printf(P4"Time to sleep must be between 1 to 200\n"OG), 1);
	av++;
	if (*av)
	{
		if (ft_atoi(*av) < 1 || ft_atoi(*av) > 200)
			return (printf(P5"Number of meals must be between 1 to 200\n"OG), 1);
	}
	return (0);
}

int	inputcheck(int ac, char **av)
{
	int	i;
	int	j;

	if ((ac != 5 && ac != 6) || !av)
		return (errormessage(1), 1);
	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9')
				return (errormessage(2), 1);
			i++;
		}
		j++;
	}
	if (maxmincheck(av))
		return (1);
	return (0);
}
