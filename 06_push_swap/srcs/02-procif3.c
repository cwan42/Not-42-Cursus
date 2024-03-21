/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/22 06:15:17 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numax(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = tmp->p->nu;
	while (tmp->n != *a)
	{
		if (tmp->nu > i)
			i = tmp->nu;
		tmp = tmp->n;
	}
	return (i);
}

int	numin(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = tmp->p->nu;
	while (tmp->n != *a)
	{
		if (tmp->nu < i)
			i = tmp->nu;
		tmp = tmp->n;
	}
	return (i);
}

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

int	stacksorted(t_stack	**a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (i != stacksize(a) && tmp->nu != (*a)->nu)
	{
		i++;
		tmp = tmp->n;
		if (tmp->nu > tmp->n->nu)
			return (1);
	}
	return (0);
} // need to fix, prob cos using circular list so need to find way to temrinate

t_stack	*mediannode(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;	
	while (i < (stacksize(a) / 2))
	{
		tmp = tmp->n;
		i++;
	}
	return (tmp);
}

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
}

void	init5(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	while (stacksize(a) > 3)
		pb(a, b);
	init3(a);
}

int	initpri(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || !b)
		return (1);
	size = stacksize(a);
//	if (size > 0 && size < 4)
//		init3(a);
//	else if (size > 3 && size < 6)
	if (size < 6)
		init5(a, b);
	return (0);
}
