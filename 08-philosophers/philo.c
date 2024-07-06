/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:26:20 by cwan              #+#    #+#             */
/*   Updated: 2024/07/06 16:55:49 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errormessage(int code)
{
	if (code == 1)
	{
		printf("Incorrect number of arguments. Rerun with 4 or 5 values:\n");
		printf("No. of philosphers, time to die, eat, sleep in ms\n");
		printf("Optional number of times each philosopher must eat\n");
	}
	if (code == 2)
		printf("Wrong syntax, all values must be a positive integer or 0\n");	
	exit (1);
}

void	inputcheck(int ac, char **av)
{
	int i;
	int j;

	if ((ac != 5 && ac != 6) || !av)
		errormessage(1);
	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9')
				errormessage(2);
			i++;
		}
		j++;
	}
}

t_uni	*inituni(char **av)
{
	t_uni	*uni;

	uni = (t_uni *)malloc(sizeof(t_uni));
	av++;
	uni->np = ft_atoi(*av++);
	uni->ttd = ft_atoi(*av++);
	uni->tte = ft_atoi(*av++);
	uni->tts = ft_atoi(*av++);
	uni->nte = -1;
	if (*av)
		uni->nte = ft_atoi(*av++);
	printf("Np is %d, ttd is %d, tte is %d, tts is %d, nte is %d\n", uni->np, uni->ttd, uni->tte, uni->tts, uni->nte);
	return (uni);
}

void	freestruct(t_uni *uni)
{
	free(uni);
}

int	main(int ac, char *av[])
{
	t_uni	*uni;
	inputcheck(ac, av);
	printf("Passed inputcheck\n");
	uni = inituni(av);
	freestruct(uni);
	return (0);
}
