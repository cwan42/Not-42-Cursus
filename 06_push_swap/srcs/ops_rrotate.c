/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:03:35 by cwan              #+#    #+#             */
/*   Updated: 2024/03/08 09:52:20 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack **head)
{
	if (!*head || (!(*head)->next) || (!(*head)->prev))
		return ;
	*head = (*head)->prev;
}

void	rra(t_stack **heada)
{
	rrotate(heada);
	ft_printf("rra\n");
}

void	rrb(t_stack **headb)
{
	rrotate(headb);
	ft_printf("rrb\n");
}

void	rrr(t_stack **heada, t_stack **headb)
{
	rrotate(heada);
	rrotate(headb);
	ft_printf("rrr\n");
}
