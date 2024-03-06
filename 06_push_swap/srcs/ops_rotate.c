/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:03:22 by cwan              #+#    #+#             */
/*   Updated: 2024/03/06 20:38:38 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **heada)
{
	rotate(heada);
	ft_printf("ra\n");
}

void	rb(t_stack **headb)
{
	rotate(headb);
	ft_printf("rb\n");
}

void	rr(t_stack **heada, t_stack **headb)
{
	rotate(heada);
	rotate(headb);
	ft_printf("rr\n");
}

void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack *last;

	if (!*head || (!(*head)->next) || (!(*head)->prev))
		return ;
	first = *head;
	last = first->prev;
	last->next = first->next;
	first->next = last;
	first->prev = last->prev;
	last->prev = first;
	*head = last;
	(*head)->prev = first;
}
