/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:57:07 by cwan              #+#    #+#             */
/*   Updated: 2023/11/30 16:17:27 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int ac, char *av[])
{
	if (ac != 5 || !av[1])
	{
		errno = EINVAL;
		return(perror("Wrong num of arguments"), 0);
	}
	int id = fork();
	int n;
	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	if (id != 0)
		wait(0);
	int i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout);
		i++;
	}
	if (id != 0)
		printf("\n");
	return (0);
}
