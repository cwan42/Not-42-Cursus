/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/02/25 15:44:42 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack **list = NULL;
	t_stack	*newnode;
	t_stack	*head;
	int		array[] = {3, 5, 2, 1, 4};
	int		i = 0;

	list = malloc(sizeof(t_stack *));
	while (i < 5)
	{
		newnode = ft_stknew(array[i++]);
		if (!list)
			*list = newnode;
		else
			ft_stkadd_back(list, newnode);
	}
	head = *list;
	while ((*list)->next != head)
	{
		ft_printf("%d ", (*list)->num);
		*list = (*list)->next;
	}
	ft_printf("%d.\n", (*list)->num);
	ft_freestack(list, head);
	return (0);
}
