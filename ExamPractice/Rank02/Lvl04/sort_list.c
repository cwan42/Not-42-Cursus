/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:46:50 by cwan              #+#    #+#             */
/*   Updated: 2024/01/05 16:11:28 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		tmp;
	t_list	*node;

	node = lst;
	while (lst->next)
	{
		if (!(*cmp)(lst->data, lst->next->data))
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = node;
		}
		else
			lst = lst->next;
	}
	return (node);
}

#include <stdlib.h>
#include <stdio.h>

int	ascending(int a, int b)
{
	return (a <= b); 
}

int	descending(int a, int b)
{
	return (a >= b);
}

t_list	*createnode(int n)
{
	t_list	*newnode;

	newnode = (t_list*)malloc(sizeof(t_list));
	if (newnode)
	{
		newnode->data = n;
		newnode->next = NULL;
	}
	return (newnode);
}

int	main(void)
{
	t_list	*list = NULL;
	t_list	*newnode;
	t_list	*temp;
	int		array[] = {3, 5, 8, 1, 2};
	int		i = 0;

	while (i < 5)
	{
		newnode = createnode(array[i]);
		if (!list)
			list = newnode;
		else
		{
			temp = list;
			while (temp->next)
				temp = temp->next;
			temp->next = newnode;
		}
		i++;
	}
	list = sort_list(list, ascending);
	temp = list;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	list = sort_list(list, descending);
	temp = list;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}

/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------
Write the following functions:
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.
Duplications must remain.
Inputs will always be consistent.
You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.
Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.
For example, the following function used as cmp will sort the list 
in ascending order:
int ascending(int a, int b)
{
	return (a <= b);
} */
