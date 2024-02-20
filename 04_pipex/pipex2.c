/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:04:04 by cwan              #+#    #+#             */
/*   Updated: 2024/02/20 09:37:46 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

const extern char	**environ;

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
	char	*cmd;

	while (*(environ) && (ft_strncmp(*(environ), "PATH=", 5)))
		environ++;
	path = ft_split(*(environ) + 5, ':');
	tmptr = path;
	cmd = ft_strjoin("/", cmdzero);
	while (*tmptr)
	{
		testpath = ft_strjoin(*(tmptr), cmd);
		if (!access(testpath, X_OK))
			return (ft_free(path), free(cmd), testpath);
		free(testpath);
		tmptr++;
	}
	ft_printf("command not found: %s\n", cmdzero);
	return (ft_free(path), free(cmd), tmptr = NULL, NULL);
}

int	ft_process(char *file, char *cmd, int fd, int pid)
{
	char	**cmdsplit;
	char	*cmdpath;
	int		filefd;

	cmdsplit = ft_split(cmd, ' ');
	cmdpath = ft_findpath(cmdsplit[0]);
	if (!cmdpath)
		return (ft_free(cmdsplit), 127);
	if (pid == 0)
	{
		filefd = open(file, O_RDONLY | R_OK);
//		if (errno == ENOENT)
//			return (ft_printf("no such file or directory: %s\n", file));
		dup2(filefd, 0);
		dup2(fd, 1);
	}
	else
	{
		filefd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(filefd, 1);
		dup2(fd, 0);
	}
	if (filefd == -1)
		return (ft_free(cmdsplit), free(cmdpath), \
		ft_putstr_fd("permission denied: ", 2), ft_putstr_fd(file, 2), 1);
	return (close(filefd), execve(cmdpath, cmdsplit, NULL), 0);
}

int	main(int ac, char *av[])
{
	int	pid;
	int	pipefd[2];
	int	exitc;

	exitc = 0;
	if (ac != 5)
		return (ft_printf("Prog req 4 arguments.\n"), 3);
	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		ft_process(av[1], av[2], pipefd[1], pid);
	else
	{
		waitpid(pid, NULL, 0);
		close(pipefd[1]);
		exitc = ft_process(av[4], av[3], pipefd[0], pid);
	}
	return (exitc);
}
