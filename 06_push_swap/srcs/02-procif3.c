/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/24 17:26:58 by cwan             ###   ########.fr       */
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
		(void)(sa(a),ra(a));
	else if ((*a)->nu > (*a)->n->nu && (*a)->nu < (*a)->p->nu)
		sa(a);
	else if ((*a)->nu < (*a)->n->nu && (*a)->nu > (*a)->p->nu)
		rra(a);
	else if ((*a)->nu > (*a)->n->nu && (*a)->n->nu < (*a)->p->nu)
		ra(a);
	else if ((*a)->nu > (*a)->n->nu && (*a)->n->nu > (*a)->p->nu)
		(void)(sa(a),rra(a));
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
	if (stacksortedrev(b))
		sb(b);
	while (*b)
	{
		while (stepsreq(indexb2a(a, b), a) > 0)
			ra(a);
		while (stepsreq(indexb2a(a, b), a) < 0)
			rra(a);
		if (!stepsreq(indexb2a(a, b), a) && ((!stacksorted(a) && \
		((*b)->nu < numin(a) || (*b)->nu > numax(a))) || \
		((*b)->nu < (*a)->nu && (*b)->nu > (*a)->p->nu)))
			pa(a, b);
		else if ((*b)->nu > mediannode(a)->nu)
			ra(a);
		else
			rra(a);
	}
	while (stacksorted(a) && (*a)->nu > numin(a))
		rra(a);
}

void	initall(t_stack **a, t_stack **b)
{
	if (!a || !b || !stacksorted(a))
		return ;
	(void)(pb(a, b), pb(a, b));
}

int	initpri(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b)
		return (1);
	if (stacksize(a) < 6)
		init5(a, b);
	else
		initall(a, b);
	return (0);
}
