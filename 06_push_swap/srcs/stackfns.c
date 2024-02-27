/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:05:49 by cwan              #+#    #+#             */
/*   Updated: 2024/02/27 18:28:09 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stklast(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != lst)
		last = last->next;
	return (last);
}

t_stack	*ft_stknew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
			return (NULL);
	new->num = value;
	new->next = new;
	new->prev = new;
	return (new);
}

void	ft_stkadd_back(t_stack **lst, t_stack *node)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		last = ft_stklast(*lst);
		node->next = *lst;
		node->prev = last;
		last->next = node;
		(*lst)->prev = node;
	}
}

void	ft_freestack(t_stack **lst, t_stack *head)
{
	t_stack	*current = *lst;
	t_stack	*nextnode;

	if (!lst)
		return ;
	while (current->next != head)
	{
		nextnode = current->next;
		free(current);
		current = nextnode;
	}
	free (current);
	*lst = NULL;
}
