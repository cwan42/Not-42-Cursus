/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/20 20:11:14 by cwan             ###   ########.fr       */
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
	if ((*a)->nu > (*a)->n->nu && (*a)->n->nu < (*a)->p->nu)
		sa(a);
	ft_printf("initif3 is running\n");
//	else if (*a
}

int	initpri(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || !b)
		return (1);
	size = stacksize(a);
	if (size == 3)
		initif3(a, b);
	return (0);
}
