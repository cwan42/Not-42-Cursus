/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/21 20:35:51 by cwan42           ###   ########.fr       */
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

int	issmol(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;

	if (!a || !*a)
		return (2);
	while (*a && tmp->n->nu != (*a)->nu)
	{
		if (tmp->nu < tmp->n->nu)
			tmp = tmp->n;
		else
			return (ft_printf("issmol=1"), 1);
	}
	return (ft_printf("issmol=0"), 0);
}
void	init2or3(t_stack **a)
{
	if (!a || !*a)
		return ;
	if (((*a)->n == *a) || ((*a)->n->n == *a && (*a)->n->n == \
	*a && (*a)->nu < (*a)->n->nu))
		return;
	else if ((*a)->n->n == *a && (*a)->nu > (*a)->n->nu)
		sa(a);
	else if ((*a)->nu < (*a)->n->nu && (*a)->n->nu < (*a)->p->nu)
		return ;
	else if ((*a)->nu < (*a)->n->nu && (*a)->nu < (*a)->p->nu)
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
	while ((*a)->n->n->n != *a)
		pb(a, b);
	init2or3(a);
/*	while (*b)
	{
		if ((*a)->p->nu > (*b)->nu)
			rra(a);
		if ((*a)->p->nu < (*b)->nu && (*a)->nu > (*b)->nu)
			(void)pa(a, b), ra(a);
	}
	ra(a);*/
}

int	initpri(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || !b)
		return (1);
	size = stacksize(a);
	if (size > 0 && size < 4)
		init2or3(a);
	else if (size > 3 && size < 6)
		initif4or5(a, b);
	return (0);
}
