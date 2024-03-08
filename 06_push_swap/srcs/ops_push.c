/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:32 by cwan              #+#    #+#             */
/*   Updated: 2024/03/08 16:33:50 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **heada, t_stack **headb)
{
	t_stack	*oga;
	t_stack	*ogb;

	if (!*heada || !*headb)
		return ;
	oga = *heada;
	ogb = *headb;
	(*heada)->prev->next = (*heada)->next;
	(*heada)->next->prev = (*heada)->prev;
	*heada = (*heada)->next;
	if (*headb)
	{
		oga->next = *headb;
		oga->prev = (*headb)->prev;
		*headb = oga;
		(*headb)->prev->next = oga;
	}
	else
	{
		*headb = oga;
		oga->next = oga;
		oga->prev = oga;
	}
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
