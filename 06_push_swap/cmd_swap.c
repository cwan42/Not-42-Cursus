/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:30:21 by cwan              #+#    #+#             */
/*   Updated: 2024/01/03 10:44:34 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **node)
{
	if (*node && (*node)->next)
	{
		*node = (*node)->next;
		(*node)->prev->prev = *node;
		(*node)->prev->next = (*node)->next;
		if ((*node)->next)
			(*node)->next->prev = (*node)->prev;
		(*node)->next = (*node)->prev;
		(*node)->prev = NULL;
	}
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
