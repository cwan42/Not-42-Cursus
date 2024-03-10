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

static	void	push(t_stack **heada, t_stack **headb)
{
	t_stack	*oga;
	t_stack	*ogb;

	if (!*heada)
		return ;
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
		ogb->prev = *headb;
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
	push(headb, heada);
	ft_printf("pa\n");
}

void	pb(t_stack **heada, t_stack **headb)
{
	push(heada, headb);
	ft_printf("pb\n");
}
