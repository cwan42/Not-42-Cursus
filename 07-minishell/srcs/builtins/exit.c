/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:09:30 by cwan              #+#    #+#             */
/*   Updated: 2024/09/26 02:28:20 by cwan42           ###   ########.fr       */
/*   Updated: 2024/07/01 09:37:18 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freeenv(t_env **env)
{
	t_env	*node;

	if (!env || !*env)
		return ;
	while (*env)
	{
		node = *env;
		*env = (*env)->n;
		if (node->name)
			free(node->name);
		if (node->value)
			free(node->value);
		if (node)
			free(node);
	}
	*env = NULL;
	free(env);
}

void	freecmdtab(t_cmd **tab)
{
	t_cmd	*tmp;

	if (!tab || !*tab)
		return ;
	while (*tab)
	{
		tmp = *tab;
		if ((*tab)->redir)
			free((*tab)->redir);
		if ((*tab)->cmd)
			free((*tab)->cmd);
		if ((*tab)->rd)
			freearr((*tab)->rd);
		if ((*tab)->cmds)
			freearr((*tab)->cmds);
		*tab = tmp->n;
		free(tmp);
	}
	free(tab);
}

int	freeheredocs(t_tools *tools)
{
	int	tmp;
	int	i;

	tmp = tools->ecode;
	i = 0;
	while (i < 10)
	{
		if (tools->hdname[i])
		{
			unlink(tools->hdname[i]);
			free(tools->hdname[i]);
			tools->hdname[i] = NULL;
		}
		if (tools->dfd[i] != -1)
		{
			close(tools->dfd[i]);
			tools->dfd[i] = -1;
		}
		i++;
	}
	return (tmp);
}

int	quietquit(t_tools *tools)
{
	int	tmp;

	tmp = tools->ecode;
	freeheredocs(tools);
	if (tools->env)
		freeenv(tools->env);
	if (tools->cmdtab)
		freecmdtab(tools->cmdtab);
	if (tools)
		free(tools);
	rl_clear_history();
	exit(tmp);
}

int	exithell(t_tools *tools, char **cmds)
{
	int	i;

	i = 0;
	if (cmds && cmds[1])
	{
		cmds++;
		if (cmds[0][i] == '-' || cmds[0][i] == '+')
			i++;
		while (cmds[0][i])
		{
			if (!ft_isdigit(cmds[0][i]))
				return (printf("exit\n"), \
				ft_putstr_fd("exit: numeric argument required\n", 2), \
				tools->ecode = 2, quietquit(tools));
			i++;
		}
		if (cmds[1])
			return (printf("exit\n"), \
			ft_putstr_fd("exit: too many arguments\n", 2), tools->ecode = 1);
		tools->ecode = ft_atoi(cmds[0]);
		if (tools->ecode < 0)
			tools->ecode = 256 + tools->ecode;
	}
	return (printf("exit\n"), quietquit(tools));
}
