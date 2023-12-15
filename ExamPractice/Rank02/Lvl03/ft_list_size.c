/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:27:09 by cwan              #+#    #+#             */
/*   Updated: 2023/12/15 15:34:50 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
/*
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

#include <stdio.h>

int	main(int ac, char *av[])
{
	int		i;
	t_list	*newnode;
	t_list	*head = NULL;
	void	*test = "xyz";

	i = 0;
	while (ac == 2 && i < atoi(av[1]))
	{
		newnode = createnode(test);
		newnode->next = head;
		head = newnode;
		i++;
	}
	printf("Size of list is %d\n", ft_list_size(head));
}
*/

/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------
Write a function that returns the number of elements in the linked list that's
passed to it.
It must be declared as follows:
int	ft_list_size(t_list *begin_list);
You must use the following structure, and turn it in as a file called
ft_list.h:
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/
