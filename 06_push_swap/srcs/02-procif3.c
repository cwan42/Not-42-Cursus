/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/22 07:25:23 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stepstome(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	if ((*b)->nu < mediannode(a)->nu)
	{
		while ((*b)->nu < tmp->nu)
		{
			tmp = tmp->n;
			i++;
		}
	}
	else if ((*b)->nu > mediannode(a)->nu)
	{
		while ((*b)->nu > tmp->p->nu)
		{
			tmp = tmp->p;
			i--;
		}
	}
	else if ((*b)->nu > numax(a) || (*b)->nu < numin(a))
		i = 1;
	return (i);
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
//	if (*b)
//		ft_printf("mediannode %d, steps are %d\n", mediannode(a)->nu, stepstome(a, b));
}

int	initpri(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b)
		return (1);
	if (stacksize(a) < 6)
		init5(a, b);
	return (0);
}
