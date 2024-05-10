/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:33:36 by cwan              #+#    #+#             */
/*   Updated: 2024/05/10 12:34:53 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_tools *tools, char **envp)
{
	int		i;
	t_list	*node;

	i = 0;
	tools->env = malloc(sizeof(t_list *));
	*tools->env = NULL;
	while (envp[i])
	{
		node = ft_lstnew(envp[i]);
		if (!node)
			return ;
		ft_lstadd_back(tools->env, node);
		i++;
	}
}

void	print_env(t_tools *tools)
{
	t_list	*node;

	node = *tools->env;
	while (node)
	{
		printf("%s\n", (char *)node->content);
		node = node->next;
	}
}
