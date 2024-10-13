/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:40:16 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/27 16:51:49 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	manage_file_descriptors(t_tools *tools, t_cmd *tab)
{
	int	incpy;
	int	outcpy;

	incpy = dup(STDIN_FILENO);
	outcpy = dup(STDOUT_FILENO);
	if (dupredir(tools, tab->rd) == -1)
	{
		resetfds(incpy, outcpy);
		close(incpy);
		close(outcpy);
		return (1);
	}
	close(incpy);
	close(outcpy);
	return (0);
}

static int	handle_commands(t_tools *tools, t_cmd *tab, int incpy, int outcpy)
{
	char	**arr;

	arr = tab->cmds;
	if (!ft_strcmp(arr[0], "env"))
		print_env(tools, tab);
	else if (!ft_strcmp(arr[0], "cd"))
		tools->ecode = cd(tools);
	else if (!ft_strcmp(arr[0], "pwd"))
		ft_pwd(tools);
	else if (!ft_strcmp(arr[0], "exit"))
	{
		close(incpy);
		close(outcpy);
		return (exithell(tools, arr), 1);
	}
	else if (!ft_strcmp(arr[0], "unset"))
		ft_unset(tools);
	else if (!ft_strcmp(arr[0], "export"))
		tools->ecode = ft_export(tools);
	else if (!ft_strcmp(arr[0], "echo"))
		tools->ecode = ft_echo(tab);
	else
		tools->ecode = 127;
	return (0);
}

int	fakeparser(t_tools *tools, t_cmd *tab)
{
	int	incpy;
	int	outcpy;

	incpy = dup(STDIN_FILENO);
	outcpy = dup(STDOUT_FILENO);
	if (manage_file_descriptors(tools, tab) == 1)
		return (1);
	handle_commands(tools, tab, incpy, outcpy);
	resetfds(incpy, outcpy);
	close(incpy);
	close(outcpy);
	return (tools->ecode);
}
