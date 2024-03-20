/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:03:22 by cwan              #+#    #+#             */
/*   Updated: 2024/03/20 20:08:00 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	if (!*head || (!(*head)->n) || (!(*head)->p))
		return ;
	*head = (*head)->n;
}

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
