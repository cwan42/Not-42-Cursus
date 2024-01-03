/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:30:21 by cwan              #+#    #+#             */
/*   Updated: 2024/01/03 12:57:37 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *node)
{
/*
	int	tmp;

	if (!node || !node->next)
		return ;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
*/
/*	if (*node && (*node)->next)
	{
		*node = (*node)->next;
		(*node)->prev->prev = *node;
		(*node)->prev->next = (*node)->next;
		if ((*node)->next)
			(*node)->next->prev = (*node)->prev;
		(*node)->next = (*node)->prev;
		(*node)->prev = NULL;
	}*/
}

void	sa(t_stack *a)
{
	if (a && a->next)
	{
	ft_printf("B4 swap: (*a)->value = %d, (*a)->next->value = %d\n", a->value, a->next->value);
	swap(a);
	ft_printf("After swap: (*a)->value = %d, (*a)->next->value = %d\n", a->value, a->next->value);
	ft_printf("sa\n");
	}
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
