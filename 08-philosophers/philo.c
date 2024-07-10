/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:26:20 by cwan              #+#    #+#             */
/*   Updated: 2024/07/10 09:58:09 by cwan             ###   ########.fr       */
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
		printf("Wrong syntax, all values must be a positive integer\n");
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

void	inituni(t_uni *uni, char **av)
{
	av++;
	uni->np = ft_atoi(*av++);
	uni->ttd = ft_atoi(*av++) * 1000;
	uni->tte = ft_atoi(*av++) * 1e3;
	uni->tts = ft_atoi(*av++) * 1000;
	uni->nte = -1;
	if (*av)
		uni->nte = ft_atoi(*av++);
	uni->endgame = 0;
	uni->philos = (t_philo *)malloc(sizeof(t_philo) * uni->np);
//	if (!uni->philos) free philos structs		
}

void	freestruct(t_uni *uni)
{
	free(uni);
}

void	*doit()
{
	printf("testing thread\n");
	usleep(3000000);
	printf("Ending thread\n");
	return (0);
}

void	initdata(t_uni *uni)
{
	pthread_t	pp, pp2;

	pthread_create(&pp, NULL, &doit, NULL);
	pthread_create(&pp2, NULL, &doit, NULL);
	pthread_join(pp, NULL);
	pthread_join(pp2, NULL);
	printf("In initdata, uni ptr = %p\n", uni);
}

int	main(int ac, char *av[])
{
	t_uni	*uni;

	uni = (t_uni *)malloc(sizeof(t_uni));
	inputcheck(ac, av);
	inituni(uni, av);
	printf("np is %d, ttd is %d, tte is %d, tts is %d, nte is %d\n", uni->np, uni->ttd, uni->tte, uni->tts, uni->nte);
	printf("Endgame is %d\n", uni->endgame);
	initdata(uni);
	freestruct(uni);
	return (0);
}
