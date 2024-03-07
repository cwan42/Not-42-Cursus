/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/03/07 16:17:04 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printloop(t_stack **list)
{
	t_stack *head = *list;

	while (head->next != *list)
	{
		ft_printf("%d ", head->num);
		head = head->next;
		ft_printf("(hnn = %d, hpn = %d) ", head->next->num, head->prev->num);
	}
	ft_printf("%d.\n", head->num);
}

int	main(void)
{
	t_stack **list = NULL;
	t_stack	*newnode;
	int		array[] = {3, 5, 2, 1, 4};
	int		i = 0;

	list = malloc(sizeof(t_stack *));
	if (!list)
		return (1);
	*list = NULL;
	while (i < 5)
	{
		newnode = ft_stknew(array[i++]);
		if (!newnode)
			return (ft_freestack(list), 1);
		ft_stkadd_back(list, newnode);
	}
	printloop(list);
	rra(list);
	sb(list);
	printloop(list);
	ra(list);
	rb(list);
	sa(list);
	printloop(list);
	
	ft_freestack(list);
	return (0);
}
