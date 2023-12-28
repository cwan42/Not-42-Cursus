/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:43:48 by cwan              #+#    #+#             */
/*   Updated: 2023/12/28 13:32:29 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*node;

	node = begin_list;
	while (node)
	{
		(*f)(node->data);
		node = node->next;
	}
}
/*
#include <stdlib.h>
#include <stdio.h>

void	printint(void *data)
{
	printf("%d ", *(int *)data);
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

int	main(void)
{
	t_list *list = NULL;
	t_list *newnode;
	t_list *temp;
	int	array[] = {1, 3, 5, 2, 4, 6};
	int	i = 0;

	while (i < 6)
	{
		newnode = createnode((void *)&array[i]);
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
	ft_list_foreach(list, &printint);
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}
*/
/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------
Write a function that takes a list and a function pointer, and applies this
function to each element of the list.
It must be declared as follows:
void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
The function pointed to by f will be used as follows:
(*f)(list_ptr->data);
You must use the following structure, and turn it in as a file called
ft_list.h:
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list; */
