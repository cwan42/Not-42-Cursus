/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:09:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/16 14:50:21 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	freelist(t_list **lst)
{
	t_list	*node;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		if (node)
			free(node);
	}
	*lst = NULL;
}

int	exithell(t_tools *tools)
{
	freearr(tools->cmds);
	freelist(tools->env);
	exit (0);
}
