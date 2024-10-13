/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XX-cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:37:25 by cwan              #+#    #+#             */
/*   Updated: 2024/10/13 10:45:08 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_uni *uni)
{
	int	i;

	i = uni->np;
	while (i--)
		pthread_mutex_destroy(&uni->philos[i].fork);
	free(uni->philos);
	free(uni);
}
