/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:57:07 by cwan              #+#    #+#             */
/*   Updated: 2023/12/06 18:54:19 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

char	*ft_findpath(char *cmdzero, char **envp)
{
	char	**path;
	char	*testpath;
	int		i;

	if (!*envp || !envp)
		return (NULL);
	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "PATH=", 5)))
		{
			path = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	i = 0;
	while (path[i])
	{
		testpath = ft_strjoin(ft_strjoin(path[i], "/"), cmdzero);
		if (!(access(testpath, F_OK)))
			return (free(path), testpath);
		free(testpath);
		i++;
	}
	return (free(path), NULL);
}

void	ft_process(char *file, char *cmd, int fd, char **envp)
{
	char	**cmdsplit;
	char	*cmdpath;
	int		filefd;

	cmdsplit = ft_split(cmd, ' ');
	cmdpath = ft_findpath(cmdsplit[0], envp);
	if (fd == 0)
	{
		filefd = open(file, O_RDONLY | O_CREAT, 0644);
		dup2(filefd, 0);
		dup2(fd, 1);
		printf("child newfd is %d\n", fd);
	}
	else
	{
		filefd = open(file, O_WRONLY | O_CREAT, 0644);
		dup2(filefd, 1);
		dup2(fd, 0);
		printf("parent newfd is %d\n", fd);
	}
	if (execve(cmdpath, cmdsplit, envp) == -1)
		perror("execve failed");
	free(cmdpath);
	free(cmdsplit);
	exit(0);
}

int	main(int ac, char *av[], char *envp[])
{
	int	pid;
	int	pipefd[2];

	if (ac != 5 || !av[1])
		return (errno = EINVAL, perror("Wrong argument count"), 0);
	(void)(pipe(pipefd), pid = fork());
	if (pid == -1)
		return (errno = EPERM, perror("Failed fork: "), 0);
	if (pid == 0)
	{
		close(pipefd[0]);
		printf("Outgoing fd is %d\n", pipefd[1]);
		ft_process(av[1], av[2], pipefd[1], envp);
	}
	else
	{
		wait(NULL);
		close(pipefd[1]);
		printf("Ingoing fd is %d\n", pipefd[1]);
		ft_process(av[4], av[3], pipefd[0], envp);
	}
	return (0);
}
