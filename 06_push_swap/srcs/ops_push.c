/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:32 by cwan              #+#    #+#             */
/*   Updated: 2024/03/08 09:47:13 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **heada, t_stack **headb)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*heada || !*headb)
		return ;
	tmp = *heada;
	*heada = (*heada)->next;
	(*heada)->prev = tmp->prev;
	tmp->prev->next = *heada;
	tmp2 = *headb;
	*headb = tmp;
	(*headb)->next = tmp2;
	(*headb)->prev = tmp2->prev;
	tmp2->prev->next = *headb;
	tmp2->next->prev = *headb;
}

void	pa(t_stack **heada, t_stack **headb)
{
	push(headb, heada);
	ft_printf("pa\n");
}

void	pb(t_stack **heada, t_stack **headb)
{
	push(heada, headb);
	ft_printf("pb\n");
}
