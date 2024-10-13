/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:33:02 by cwan              #+#    #+#             */
/*   Updated: 2024/10/13 10:34:07 by cwan             ###   ########.fr       */
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

# define OG   "\033[0m"
# define P    "\033[38;5;213m"
# define P2    "\033[38;5;205m"
# define P3   "\033[38;5;199m"
# define P4    "\033[38;5;198m"
# define P5   "\033[38;5;206m"

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	pthread_mutex_t	fork;
	int				nme;
	int				lte;
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
	t_philo	*philos;
	struct timeval start;
}			t_uni;

//01-inputvalidation.c
int		inputcheck(int ac, char **av);

//01-inituni.c
void	inituni(t_uni *uni, char **av);

//XX-cleanup.c
void cleanup(t_uni *uni);

//utils.c
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t numelem, size_t size);

#endif
