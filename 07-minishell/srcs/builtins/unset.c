/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:00:48 by cwan              #+#    #+#             */
/*   Updated: 2024/09/20 15:09:21 by cwan             ###   ########.fr       */
/*   Updated: 2024/05/22 23:57:44 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delnode(t_tools *tools, t_env *node, t_env *prenode)
{
	if (node == *tools->env)
		*tools->env = node->n;
	else if (!node->n)
		prenode->n = NULL;
	else
		prenode->n = node->n;
	free(node->name);
	free(node->value);
	free(node);
}

void	ft_unset(t_tools *tools)
{
	t_env	*node;
	t_env	*prenode;
	int		i;

	i = 0;
	while ((*tools->cmdtab)->cmds[++i])
	{
		node = *tools->env;
		prenode = node;
		while (node)
		{
			if (!ft_strcmp(node->name, (*tools->cmdtab)->cmds[i]))
			{
				delnode(tools, node, prenode);
				break ;
			}
			prenode = node;
			node = node->n;
		}
	}
	tools->ecode = 0;
}
