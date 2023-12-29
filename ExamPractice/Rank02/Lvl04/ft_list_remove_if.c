/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:44:29 by cwan              #+#    #+#             */
/*   Updated: 2023/12/29 11:00:47 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*node;

	if (!begin_list || !*begin_list)
		return ;
	node = *begin_list;
	if (cmp(node->data, data_ref) == 0)
	{
		*begin_list = node->next;
		free(node);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	node = *begin_list;
	ft_list_remove_if(&node->next, data_ref, cmp);
}

t_list	*createnode(void *data)
{
	t_list	*newnode;

	newnode = (t_list*)malloc(sizeof(t_list));
	if (newnode)
	{
		newnode->data = data;
		newnode->next = NULL;
	}
	return (newnode);
}

#include <string.h>
#include <stdio.h>

int	cmpint(void *a, void *b)
{
	return (*(int *)a == *(int *)b);
}

int	main(void)
{
	t_list	*list = NULL;
	t_list	*newnode;
	t_list	*temp;
	int		array[] = {1, 2, 3, 4, 5};
	int		i = 0;

	while (i < 5)
	{
		newnode = createnode ((void *)&array[i]);
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
	ft_list_remove_if(&list, (void *)1, cmpint);
	while (list)
	{
		printf("%d ", *((int *)list->data));
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}

/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------
Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.
It will be declared as follows :
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
cmp takes two void* and returns 0 when both parameters are equal.
You have to use the ft_list.h file, which will contain:
$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$> */
