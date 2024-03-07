/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:43 by cwan              #+#    #+#             */
/*   Updated: 2024/03/07 18:49:58 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap(t_stack **head)
{
	t_stack	*third;

	if (!*head || (!(*head)->next))
		return ;
	third = NULL;
	if ((*head)->next->next != *head)
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
	else
		*head = (*head)->next;
/*
	first = *head;
	second = first->next;
	last = first->prev;
	last->next = second;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = (*head)->prev;
	*head = second;
	(*head)->next = first;
	(*head)->prev = last;*/
}
