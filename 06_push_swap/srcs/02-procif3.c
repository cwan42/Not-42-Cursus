/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/24 03:22:16 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init3(t_stack **a)
{
	if (!a || !*a)
		return ;
	if ((*a)->nu < (*a)->n->nu && (*a)->n->nu < (*a)->p->nu)
		return ;
	if ((*a)->nu < (*a)->n->nu && (*a)->nu < (*a)->p->nu)
		(void)sa(a),ra(a);
	else if ((*a)->nu > (*a)->n->nu && (*a)->nu < (*a)->p->nu)
		sa(a);
	else if ((*a)->nu < (*a)->n->nu && (*a)->nu > (*a)->p->nu)
		rra(a);
	else if ((*a)->nu > (*a)->n->nu && (*a)->n->nu < (*a)->p->nu)
		ra(a);
	else if ((*a)->nu > (*a)->n->nu && (*a)->n->nu > (*a)->p->nu)
		(void)sa(a),rra(a);
}
/*	init3 shorter ver
void	init3(t_stack **a)
{
	if (stacksize(a) < 3 && (*a)->nu > (*a)->n->nu)
		sa(a);
	else if (stacksize(a) == 3)
	{
		if ((*a)->nu == numax(a))
			ra(a);
		else if ((*a)->n->nu == numax(a))
			rra(a);
		if ((*a)->nu > (*a)->n->nu)
			sa(a);
	}
}*/

void	init5(t_stack **a, t_stack **b)
{
	if (!a || !b || !stacksorted(a))
		return ;
	while (stacksize(a) > 3)
		pb(a, b);
	init3(a);
	if (!stacksorted(b))
		sb(b);
	while (*b)
	{
		if ((*b)->nu > (*a)->p->nu && ((*b)->nu < (*a)->nu ||\
		 (*a)->p->nu == numax(a)))
			pa(a, b);
		else if ((*b)->nu < numin(a) && (*a)->p->nu == numax(a))
			pa(a, b);
		else if ((*b)->nu < (*a)->nu && (*b)->nu > (*a)->p->nu)
			pa(a, b);
		else
			ra(a);
	}
//	while (stacksorted(a))
//		rra(a);
//2 3 1 4 5
}
/*
	while (*b && !stacksorted(a))
	{
		if (((*b)->nu > ft_stklast(*a)->nu && ft_stklast(*a)->nu == numax(a)) ||\
			(((*b)->nu < (*a)->nu && (*b)->nu > (*a)->p->nu)))
			(void)(pa(a, b),ra(a));
		else if ((*b)->nu < numax(a) && (*b)->nu > (*a)->nu)
			ra(a);
	}
	while (stacksorted(a))
		ra(a);		
}*/

int	initpri(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b)
		return (1);
	if (stacksize(a) < 6)
		init5(a, b);
	return (0);
}
