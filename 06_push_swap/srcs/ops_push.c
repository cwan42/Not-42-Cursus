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

static	void	pushifooz(t_stack **heada, t_stack **headb)
{
	t_stack	*ogb;

	if ((*heada == (*heada)->next) && !*headb)
	{
		*headb = *heada;
		*heada = NULL;
	}
	else if ((*heada != (*heada)->next) && !*headb)
	{
		ogb = *headb;
		(*headb)->prev->next = *heada;
		*headb = *heada;
		(*headb)->prev = ogb->prev;
		(*headb)->next = ogb;
	}
}

static	void	push(t_stack **heada, t_stack **headb)
{
	t_stack	*oga;
	t_stack	*ogb;

	oga = *heada;
	(*heada)->prev->next = (*heada)->next;
	(*heada)->next->prev = (*heada)->prev;
	*heada = (*heada)->next;
	if (*headb)
	{
		ogb = *headb;
		ogb->prev->next = oga;
		*headb = oga;
		(*headb)->prev = ogb->prev;
		(*headb)->next = ogb;
		ogb->prev = oga;
	}
	else
	{
		*headb = oga;
		(*headb)->prev = oga;
		(*headb)->next = oga;
	}
}

void	pa(t_stack **heada, t_stack **headb)
{
	if (!*heada)
		return ;
	if (*headb == (*headb)->next || !*heada)
		pushifooz(headb, heada);
	else
		push(headb, heada);
	ft_printf("pa\n");
}

void	pb(t_stack **heada, t_stack **headb)
{
	if (!*heada)
		return ;
	if (*heada == (*heada)->next || !*headb)
		pushifooz(heada, headb);
	else
		push(heada, headb);
	ft_printf("pb\n");
}
