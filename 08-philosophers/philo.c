/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:26:20 by cwan              #+#    #+#             */
/*   Updated: 2024/10/13 10:34:29 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*doit()
{
	printf("testing thread\n");
	return (0);
}

void	initdata(t_uni *uni)
{
	int	i = 0;
	while (i < uni->np)
	{
		pthread_create(&uni->philos->tid, NULL, &doit, NULL);
		pthread_join(uni->philos->tid, NULL);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_uni	*uni;

	uni = (t_uni *)malloc(sizeof(t_uni));
	if (inputcheck(ac, av))
		return (free(uni), 1);
	inituni(uni, av);
	initdata(uni);
	cleanup(uni);
	return (0);
}
