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
	usleep(3000000);
	printf("Ending thread\n");
	return (0);
}

void	initdata(t_uni *uni)
{
	pthread_t	pp;
	pthread_t	pp2;

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
	if (inputcheck(ac, av))
		return (free(uni), 1);
	inituni(uni, av);
	initdata(uni);
	cleanup(uni);
	return (0);
}
