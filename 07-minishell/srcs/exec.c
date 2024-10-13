/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:55:27 by cwan              #+#    #+#             */
/*   Updated: 2024/09/27 18:10:56 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	perform_redirection(int type, int fdin, int fdout, char **files)
{
	if (type == 0)
	{
		if (dup2(fdin, STDIN_FILENO) == -1)
		{
			if (access(files[0], F_OK) == -1)
				return (errmsg(files[0], NULL, 1), -1);
			else
				return (errmsg(files[0], NULL, 3), -2);
			return (-1);
		}
	}
	else if (type == 1)
	{
		if (dup2(fdout, STDOUT_FILENO) == -1)
		{
			errmsg(files[1], NULL, 3);
			return (-2);
		}
	}
	if (fdin != STDIN_FILENO)
		close(fdin);
	if (fdout != STDOUT_FILENO)
		close(fdout);
	return (0);
}

int	redirin(char **files, int *fdin, int *i)
{
	if (*fdin != 0)
		close(*fdin);
	*fdin = open(files[*i + 1], O_RDONLY);
	if (*fdin == -1)
	{
		if (access(files[*i + 1], F_OK))
			errmsg(files[*i + 1], NULL, 1);
		else if (access(files[*i + 1], X_OK))
			errmsg(files[*i + 1], NULL, 3);
		return (-1);
	}
	*i += 2;
	return (0);
}

int	redirhd(t_tools *tools, char **files, int *fdin, int *i)
{
	int	x;

	x = 0;
	while (ft_strcmp(files[*i + 1], tools->delimiters[x]))
		x++;
	if (*fdin != 0)
		close(*fdin);
	*fdin = open(tools->hdname[x], O_RDONLY);
	if (*fdin == -1)
		return (-1);
	*i += 2;
	return (0);
}

int	redirout(char **files, int *fdout, int *i)
{
	if (*fdout != 0)
		close(*fdout);
	if (!ft_strcmp(files[*i], ">"))
		*fdout = open(files[*i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (!ft_strcmp(files[*i], ">>"))
		*fdout = open(files[*i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*fdout == -1)
	{
		if (access(files[*i + 1], F_OK))
			errmsg(files[*i + 1], NULL, 1);
		else if (access(files[*i + 1], X_OK))
			errmsg(files[*i + 1], NULL, 3);
		return (-1);
	}
	*i += 2;
	return (0);
}
