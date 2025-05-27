/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-inituni.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:25:29 by cwan              #+#    #+#             */
/*   Updated: 2024/10/13 10:33:38 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	inituni(t_uni *uni, char **av)
{
	av++;
	uni->np = ft_atoi(*av++);
	uni->ttd = ft_atoi(*av++) * 1000;
	uni->tte = ft_atoi(*av++) * 1e3;
	uni->tts = ft_atoi(*av++) * 1000;
	uni->nte = 0;
	if (*av)
		uni->nte = ft_atoi(*av++);
	uni->endgame = 0;
	uni->philos = (t_philo *)ft_calloc(uni->np, sizeof(t_philo));
	gettimeofday(&uni->start, NULL);
}
