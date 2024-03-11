/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:32 by cwan              #+#    #+#             */
/*   Updated: 2024/03/11 12:12:46 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_stack **sta, t_stack **stb)
{
	t_stack	*oga;
	t_stack	*ogb;

	oga = *sta;
	if (*sta != (*sta)->next)
	{
		(*sta)->prev->next = (*sta)->next;
		(*sta)->next->prev = (*sta)->prev;
		*sta = (*sta)->next;
	}
	else
		*sta = NULL;
	if (*stb)
	{
		ogb = *stb;
		ogb->prev->next = oga;
		*stb = oga;
		(*stb)->prev = ogb->prev;
		(*stb)->next = ogb;
		ogb->prev = oga;
	}
	else
	{
		oga->next = oga;
		oga->prev = oga;
		*stb = oga;
	}
}

void	pa(t_stack **sta, t_stack **stb)
{
	if (!*stb)
		return ;
	push(stb, sta);
	ft_printf("pa\n");
}

void	pb(t_stack **sta, t_stack **stb)
{
	if (!*sta)
		return ;
	push(sta, stb);
	ft_printf("pb\n");
}
