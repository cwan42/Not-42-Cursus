/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:14:07 by cwan              #+#    #+#             */
/*   Updated: 2024/02/15 16:03:42 by cwan             ###   ########.fr       */
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
	char	**tmp;
	char	*slashcmd;
	int		i;

	i = 0;
	path = NULL;
	while (environ[i])
	{
		if (!(ft_strncmp(environ[i], "PATH=", 5)))
		{
			path = ft_split(environ[i] + 5, ':');
			break ;
		}
		i++;
	}
	tmp = path;
	slashcmd = ft_strjoin("/", cmdzero);
	while (*tmp)
	{
		testpath = ft_strjoin(*(tmp++), slashcmd);
		if (!access(testpath, X_OK))
			return (ft_free(path), free(slashcmd), testpath);
		free(testpath);
	}
	ft_printf("command not found: %s\n", cmdzero);
	return (ft_free(path), free(slashcmd), NULL);
}

int	main(int ac, char *av[])
{
	char	*cmdpath;
	int		i;

	cmdpath = NULL;
	i = 0;
	if (ac == 2 && ft_findpath(av[1]))
	{
		cmdpath = ft_findpath(av[1]);
		printf("%s\n", cmdpath);
	}
	free(cmdpath);
	cmdpath = NULL;
	return (0);
}
