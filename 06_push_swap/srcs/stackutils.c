/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:47:38 by cwan              #+#    #+#             */
/*   Updated: 2024/03/22 06:49:21 by cwan             ###   ########.fr       */
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

	tmp = *a;
	while (tmp->n != *a)
	{
		if (tmp->nu > tmp->n->nu)
			return (1);
		tmp = tmp->n;
	}
	return (0);
}

int	stacksortedrev(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->n != *a)
	{
		if (tmp->nu < tmp->n->nu)
			return (1);
		tmp = tmp->n;
	}
	return (0);
}
