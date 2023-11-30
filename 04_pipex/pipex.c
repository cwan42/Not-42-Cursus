/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:57:07 by cwan              #+#    #+#             */
/*   Updated: 2023/11/30 18:26:47 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int ac, char *av[])
//, char *envp[])
{
	int	pid;
	int	pipefd[2];

	if (ac != 5 || !av[1])
		return(errno = EINVAL, perror("Wrong argument count"), 0);
	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return (errno = EPERM, perror("Failed fork: "), 0);
	if (pid == 0)
	{
		close(pipefd[0]);
		printf("Child process is up\n");
	}
	else
	{
		close(pipefd[1]);
		printf("Parent process is up\n");
	}
}
