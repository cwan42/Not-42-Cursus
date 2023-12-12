/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:45:26 by cwan              #+#    #+#             */
/*   Updated: 2023/12/12 18:06:20 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
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
*/

int	ft_process(char *file, char *cmd, int fd, int pid)
{
	char	**cmdsplit;
	char	*cmdpath;
	int		filefd;

	cmdsplit = ft_split(cmd, ' ');
	cmdpath = ft_strjoin("/bin/", cmdsplit[0]);
	if (access(cmdpath, F_OK))
		return (ft_printf("command not found: %s\n", cmdsplit[0]), -1);
	if (pid == 0)
	{
		filefd = open(file, O_RDONLY | R_OK);
		if (filefd == -1)
			return (ft_printf("permission denied: %s", file), -1);
		dup2(filefd, 0);
		return (dup2(fd, 1), close(filefd), execve(cmdpath, cmdsplit, NULL), 0);
	}
	else
	{
		filefd = open(file, O_WRONLY | O_CREAT, 0644);
		if (filefd == -1)
			return (ft_printf("permission denied: %s", file), -1);
		dup2(filefd, 1);
		return (dup2(fd, 0), close(filefd), execve(cmdpath, cmdsplit, NULL), 0);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	pipefd[2];

	if (ac != 5 || !av[1])
		return (ft_printf("Invalid argument count", 0));
	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		return (errno = EPERM, perror("Failed fork: "), 0);
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
