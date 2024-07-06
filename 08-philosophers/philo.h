/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:33:02 by cwan              #+#    #+#             */
/*   Updated: 2024/07/06 16:37:36 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> // memset
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread_create, detach, join
					// pthread_mutex_init, destroy, lock, unlock

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				forkid;
}					t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	threadid;
	t_fork		*lf;
	t_fork		*rf;
	int			nme;
	int			lte;
}				t_philo;

typedef struct s_uni
{
	int		np;
	int		ttd;
	int		tte;
	int		tts;
	int		nte;
	int		starttime;
	int		endgame;
	t_fork	*forks;
	t_philo *philos;
}			t_uni;

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
