/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:43 by cwan              #+#    #+#             */
/*   Updated: 2024/03/20 20:09:06 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*third;

	if (!*head || (!(*head)->n))
		return ;
	third = NULL;
	if ((*head)->n->n == *head)
		*head = (*head)->n;
	else
	{
		third = (*head)->n->n;
		(*head)->p->n = (*head)->n;
		*head = (*head)->n;
		(*head)->n = (*head)->p;
		(*head)->p = (*head)->p->p;
		(*head)->n->n = third;
		(*head)->n->p = *head;
		third->p = (*head)->n;
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
