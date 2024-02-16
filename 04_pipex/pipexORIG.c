/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:02:21 by cwan              #+#    #+#             */
/*   Updated: 2024/02/15 10:11:49 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern const char	**environ;

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*ft_findpath(char *cmdzero)
{
	char	**path;
	char	*testpath;
	char	**tmptr;

	while (*(environ) && (ft_strncmp(*(environ), "PATH=", 5)))
		environ++;
	path = ft_split(*(environ) + 5, ':');
	tmptr = path;
	while (*tmptr)
	{
		testpath = ft_strjoin(*(tmptr), cmdzero);
		if (!access(testpath, X_OK))
			return (ft_free(path), free(cmdzero), testpath);
		free(testpath);
		tmptr++;
	}
	ft_printf("command not found: %s\n", cmdzero);
	ft_free(path);
	return (ft_free(path), tmptr = NULL, NULL);
}

int	ft_process(char *file, char *cmd, int fd, int pid)
{
	char	**cmdsplit;
	char	*cmdzero;
	char	*cmdpath;
	int		filefd;

	cmdsplit = ft_split(cmd, ' ');
	cmdzero = ft_strjoin("/", cmdsplit[0]);
	cmdpath = ft_findpath(cmdzero);
	if (!cmdpath)
		return (ft_free(cmdsplit), free(cmdzero), -1);
	if (pid == 0)
	{
		filefd = open(file, O_RDONLY | R_OK);
		if (filefd == -1)
			return (ft_printf("permission denied: %s", file), -1);
		return (dup2(filefd, 0), dup2(fd, 1), close(filefd), \
		execve(cmdpath, cmdsplit, NULL), 0);
	}
	else
	{
		filefd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (filefd == -1)
			return (ft_printf("permission denied: %s", file), -1);
		return (dup2(filefd, 1), dup2(fd, 0), close(filefd), \
			execve(cmdpath, cmdsplit, NULL), 0);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	pipefd[2];

	if (ac != 5)
		return (ft_printf("Invalid argument count\n"), 1);
	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		return (errno = EPERM, perror("Failed fork: "), 1);
	if (pid == 0)
	{
		close(pipefd[0]);
		ft_process(av[1], av[2], pipefd[1], pid);
	}
	else
	{
		wait(NULL);
		close(pipefd[1]);
		ft_process(av[4], av[3], pipefd[0], pid);
	}
	return (0);
}
