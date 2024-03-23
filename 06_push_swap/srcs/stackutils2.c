/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan42 <cwan42@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 06:42:52 by cwan42            #+#    #+#             */
/*   Updated: 2024/03/24 07:25:46 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexpos(t_stack **a, int num)
{
	int	i;

	i = 0;
	while ((*a)->nu != num)
	{
		*a = (*a)->n;
		i++;
	}
	return (i);
}

int	indexb2a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	if ((*b)->nu > numax(a) || (*b)->nu < numin(a))
		return (0);
	while ((*b)->nu > tmp->nu)
	{
		if ((*b)->nu < tmp->p->nu && (*b)->nu > tmp->nu)
			return (i);
		tmp = tmp->n;
		i++;
	}
	i = 0;
	while ((*b)->nu < tmp->nu)
	{
		if ((*b)->nu < tmp->nu && (*b)->nu > tmp->n->nu)
			return (i);
		tmp = tmp->n;
		i++;
	}
	return (0);
}

int	stepsreq(int pos, t_stack **a)
{
	if (pos <= (stacksize(a)/2))
		return (pos);
	else if (pos > (stacksize(a)/2))
		return ((stacksize(a) - pos) * -1);
	else
		return (0);
}
