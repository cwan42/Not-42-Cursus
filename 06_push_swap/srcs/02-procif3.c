/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/27 07:11:59 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tgtval(t_stack **a, t_stack *b);

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
	while (stacksize(a) > 3)
		pb(a, b);
	init3(a);
	ft_printf("Targetnode is %d\n", tgtval(a, *b));
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
/*
void	initall(t_stack **a, t_stack **b)
{
	(void)(pb(a, b), pb(a, b));
//	if (stacksortedrev(b))
//		sb(b);
	while (stacksize(a) > 3)
	{
		while (stepsreq(indexa2b(a, b), b) > 0)
			rb(b);
		while (stepsreq(indexa2b(a, b), b) < 0)
			rrb(b);
		if (!stepsreq(indexa2b(a, b), b) && ((!stacksortedrev(b) && \
		((*a)->nu < numin(b) || (*a)->nu > numax(b))) || \
		((*a)->nu > (*b)->nu && (*a)->nu < (*b)->p->nu)))
			pb(a, b);
		else if ((*a)->nu < mediannode(b)->nu)
			rb(b);
		else
			rrb(b);
	}
//	while (stacksortedrev(b) && (*b)->nu != numax(b))
//		rrb(b);
	init5(a, b);
}*/

int	tgtval(t_stack **a, t_stack *b)
{
	t_stack	*tmp;

	tmp = *a;
	if ((b->nu > numax(a) || b->nu < numin(a)))
		return (numin(a));
	while (b->nu > tmp->nu)
		tmp = tmp->n;
	return (tmp->nu);
}
/*
void	cheapb2a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tgt;
	int		best;

	while (*b)
	{
		best = 10000;
		tmp = *a;
		while (tmp)
		{
			if (tmp->nu > (*b)->nu && tmp->nu < best)
			{
				best = tmp->nu;
				tgt = tmp;
			}
			tmp = tmp->n;
		}
		if 
	}
	
}*/

int	initpri(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !stacksorted(a))
		return (1);
	if (stacksize(a) < 6)
		init5(a, b);
	else
		init5(a, b);
	return (0);
}
