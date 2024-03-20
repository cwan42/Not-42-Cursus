/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:32 by cwan              #+#    #+#             */
/*   Updated: 2024/03/20 20:07:36 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_stack **sta, t_stack **stb)
{
	t_stack	*oga;

	oga = *sta;
	if (*sta != (*sta)->n)
	{
		(*sta)->p->n = (*sta)->n;
		(*sta)->n->p = (*sta)->p;
		*sta = (*sta)->n;
	}
	else
		*sta = NULL;
	if (*stb)
	{
		(*stb)->p->n = oga;
		oga->n = *stb;
		oga->p = (*stb)->p;
		(*stb)->p = oga;
		*stb = oga;
	}
	else
	{
		oga->n = oga;
		oga->p = oga;
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
