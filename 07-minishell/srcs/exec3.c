/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:07:00 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/27 17:40:27 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dupredir2(t_tools *tools, char **files, int *fdin, int *fdout)
{
	int	i;

	i = 0;
	while (files && files[i])
	{
		if (!ft_strcmp(files[i], "<"))
		{
			if (redirin(files, fdin, &i) == -1)
				return (tools->ecode = 1, -1);
		}
		else if (!ft_strcmp(files[i], "<<"))
		{
			if (redirhd(tools, files, fdin, &i) == -1)
				return (-1);
		}
		else if (!ft_strcmp(files[i], ">") || !ft_strcmp(files[i], ">>"))
		{
			if (redirout(files, fdout, &i) == -1)
				return (tools->ecode = 1, -1);
		}
	}
	return (0);
}

int	dupredir(t_tools *tools, char **files)
{
	int	fdin;
	int	fdout;
	int	prdv0;
	int	prdv1;

	fdin = STDIN_FILENO;
	fdout = STDOUT_FILENO;
	if (dupredir2(tools, files, &fdin, &fdout) == -1)
		return (-1);
	prdv0 = perform_redirection(0, fdin, fdout, files);
	prdv1 = perform_redirection(1, fdin, fdout, files);
	if (prdv0 == -1)
		tools->ecode = 127;
	else if (prdv1 == -2)
		tools->ecode = 126;
	return (prdv0 | prdv1);
}
