/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:43 by cwan              #+#    #+#             */
/*   Updated: 2024/03/08 15:29:38 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*third;

	if (!*head || (!(*head)->next))
		return ;
	third = NULL;
	if ((*head)->next->next == *head)
		*head = (*head)->next;
	else
	{
		third = (*head)->next->next;
		(*head)->prev->next = (*head)->next;
		*head = (*head)->next;
		(*head)->next = (*head)->prev;
		(*head)->prev = (*head)->prev->prev;
		(*head)->next->next = third;
		(*head)->next->prev = *head;
		third->prev = (*head)->next;
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
