/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:43 by cwan              #+#    #+#             */
/*   Updated: 2024/03/08 13:26:33 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*oldhead;
	t_stack	*newhead;

	if (!*head || (!(*head)->next))
		return ;
	oldhead = *head;
	newhead = (*head)->next;
	if ((*head)->next == *head)
		*head = (*head)->next;
	else
	{
		oldhead->prev->next = newhead;
		newhead->prev = oldhead->prev;
		oldhead->prev = newhead;
		oldhead->next = newhead->next;
		newhead->next->prev = oldhead;
		newhead->next = oldhead;
		*head = newhead;
	}
}

void	sa(t_stack **heada)
{
	swap(heada);
	ft_printf("sa\n");
}

void	sb(t_stack **headb)
{
	swap(headb);
	ft_printf("sb\n");
}

void	ss(t_stack **heada, t_stack **headb)
{
	swap(heada);
	swap(headb);
	ft_printf("ss\n");
}
