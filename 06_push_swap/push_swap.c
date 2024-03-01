/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/03/01 16:04:57 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <sys/wait.h>

int	main(void)
{
	t_stack **list = NULL;
	t_stack	*newnode;
	t_stack	*head;
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
	head = *list;
	while (head->next != *list)
	{
		ft_printf("%d ", head->num);
		head = head->next;
	}
	ft_printf("%d.\n", head->num);
	sa(list);
	head = *list;
	while (head->next != *list && i++ < 11)
	{
		ft_printf("Head/*list value is: %d, %d\n", head->num, (*list)->num);
		ft_printf("Second values are: %d, %d\n", head->next->num, (*list)->next->num);
		int	*ptr = &head->next;
		int *ptr2 = &*list;
		ft_printf("Mem add of head->next/*list = %p, %p\n", (void *)ptr, (void *)ptr2);
//		ft_printf("%d ", head->num);
		head = head->next;
	}
//	ft_printf("%d.\n", head->num);
	ft_freestack(list);
	return (0);
}
