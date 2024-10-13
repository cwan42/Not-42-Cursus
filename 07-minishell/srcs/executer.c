/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:33:58 by cwan              #+#    #+#             */
/*   Updated: 2024/09/27 15:39:53 by cbandara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isbuiltin(char *word)
{
	if (!word)
		return (0);
	if (!ft_strcmp(word, "echo") || !ft_strcmp(word, "cd") || \
	!ft_strcmp(word, "pwd") || !ft_strcmp(word, "exit") || \
	!ft_strcmp(word, "unset") || !ft_strcmp(word, "export") || \
	!ft_strcmp(word, "env"))
		return (1);
	return (0);
}

int	resetfds(int in, int out)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		close(in);
		return (-1);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		close(out);
		return (-1);
	}
	return (0);
}

int	fakeparser2(t_tools *tools, t_cmd *tab)
{
	char	**arr;

	arr = tab->cmds;
	if (!ft_strcmp(arr[0], "env"))
		print_env(tools, tab);
	else if (!ft_strcmp(arr[0], "cd"))
		tools->ecode = cd(tools);
	else if (!ft_strcmp(arr[0], "pwd"))
		tools->ecode = ft_pwd(tools);
	else if (!ft_strcmp(arr[0], "exit"))
		exithell(tools, tab->cmds);
	else if (!ft_strcmp(arr[0], "unset"))
		ft_unset(tools);
	else if (!ft_strcmp(arr[0], "export"))
		tools->ecode = ft_export(tools);
	else if (!ft_strcmp(arr[0], "echo"))
		tools->ecode = ft_echo(tab);
	return (tools->ecode);
}
