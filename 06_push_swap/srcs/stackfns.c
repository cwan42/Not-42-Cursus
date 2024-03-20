/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:05:49 by cwan              #+#    #+#             */
/*   Updated: 2024/03/20 20:10:40 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stklast(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->n != lst)
		last = last->n;
	return (last);
}

t_stack	*ft_stknew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nu = value;
	new->n = new;
	new->p = new;
	return (new);
}

void	ft_stkadd_back(t_stack **lst, t_stack *node)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = node;
		node->n = node;
		node->p = node;
	}
	else
	{
		last = ft_stklast(*lst);
		node->n = *lst;
		node->p = last;
		last->n = node;
		(*lst)->p = node;
	}
}

void	ft_freestack(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*nextnode;
	t_stack	*head;

	if (!lst || !*lst)
		return ;
	if (*lst)
	{
		tmp = *lst;
		head = *lst;
		while (tmp->n != head)
		{
			nextnode = tmp->n;
			free(tmp);
			tmp = nextnode;
		}
		free(tmp);
	}
	free(lst);
}
