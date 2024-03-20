/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/20 21:52:12 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack **a)
{
	t_stack	*ptr;
	int		count;

	ptr = *a;
	count = 1;
	while (ptr->n != *a)
	{
		ptr = ptr->n;
		count++;
	}
	return (count);
}

void	initif3(t_stack **a, t_stack **b)
{
	if (!a || !b)
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

void	initif4or5(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	while ((*a)->n->n->n->nu != (*a)->nu)
		pb(a, b);
	initif3(a, b);
//	if ((*b)->nu < (ft_stklast(*a)->nu))
}

int	initpri(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || !b)
		return (1);
	size = stacksize(a);
	if (size == 3)
		initif3(a, b);
	else if (size > 3 && size <6)
		initif4or5(a, b);
	return (0);
}
