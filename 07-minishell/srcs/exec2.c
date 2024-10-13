/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:59:37 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/27 16:49:55 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_directory(t_tools *tools, char *str)
{
	struct stat	filestat;

	if (access(str, F_OK))
		return (0);
	if (stat(str, &filestat))
		return (0);
	if (S_ISDIR(filestat.st_mode))
	{
		if (access(str, X_OK))
			return (errmsg(str, NULL, 3), tools->ecode = 126, 1);
		else if (!ft_strncmp(str, "/", 1) || !ft_strncmp(str, "./", 2))
			return (errmsg(str, NULL, 4), tools->ecode = 126, 1);
		else
			return (errmsg(str, NULL, 2), tools->ecode = 127, 1);
	}
	return (0);
}

static int	findpath2(t_tools *tools, char *cmdzero)
{
	if (cmdzero[0] == '/')
	{
		if (!access(cmdzero, F_OK))
			return (errmsg(cmdzero, NULL, 3), tools->ecode = 126, 1);
		return (errmsg(cmdzero, NULL, 1), tools->ecode = 127, 1);
	}
	else if (cmdzero[0] == '.')
	{
		if (!access(cmdzero, F_OK))
			return (errmsg(cmdzero, NULL, 3), tools->ecode = 126, 1);
		return (errmsg(cmdzero, NULL, 1), tools->ecode = 127, 1);
	}
	else
		return (0);
}

static char	*findpath3(t_tools *tools, char **path, char *cmdzero)
{
	char	*testpath;
	char	**tmptr;
	char	*cmd;

	tmptr = path;
	cmd = ft_strjoin("/", cmdzero);
	while (*tmptr)
	{
		testpath = ft_strjoin(*(tmptr), cmd);
		if (!access(testpath, X_OK))
			return (freearr(path), free(cmd), testpath);
		free(testpath);
		tmptr++;
	}
	freearr(path);
	free(cmd);
	tmptr = NULL;
	tools->ecode = 127;
	return (errmsg(cmdzero, NULL, 2), NULL);
}

char	*ft_findpath(t_tools *tools, char *cmdzero)
{
	char	**path;
	char	*testpath;
	t_env	*tmp;

	if (!cmdzero || !*cmdzero)
		return (NULL);
	tmp = *tools->env;
	if (!access(cmdzero, X_OK))
		return (cmdzero);
	else if (findpath2(tools, cmdzero))
		return (NULL);
	while (tmp && (ft_strcmp(tmp->name, "PATH")))
		tmp = tmp->n;
	if (!tmp)
		return (errmsg(cmdzero, NULL, 1), tools->ecode = 127, NULL);
	path = ft_split(tmp->value, ':');
	testpath = findpath3(tools, path, cmdzero);
	if (testpath)
		return (testpath);
	return (NULL);
}

int	execmd(t_tools *tools, t_cmd *cmd)
{
	char	*cmdpath;

	cmdpath = NULL;
	if (dupredir(tools, cmd->rd) == -1)
		return (-1);
	if (isbuiltin(cmd->cmds[0]))
		fakeparser2(tools, cmd);
	else
	{
		cmdpath = ft_findpath(tools, cmd->cmds[0]);
		if (!cmdpath || (cmd->cmds[0] && is_directory(tools, cmd->cmds[0])))
			return (-1);
		execve(cmdpath, cmd->cmds, newenvp(tools));
	}
	freeheredocs(tools);
	return (quietquit(tools), 1);
}
