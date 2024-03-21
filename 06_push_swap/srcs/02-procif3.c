/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/22 06:54:17 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
