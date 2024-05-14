/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:09:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/10 18:26:40 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void	freelist(t_list **lst )
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
	freelist(tools->env);
	exit (0);	
}
