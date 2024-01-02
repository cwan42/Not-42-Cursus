/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/01/02 12:56:21 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_createstacka(char **av, t_list **stack)
{
	t_list *node;

	while (*av)
	{
		node = ft_lstnew(ft_atoi(*av));
		if (!node)
			break ;
		ft_lstadd_back(stack, node);
		av++;
	}
}

int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || !av[1])
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	int	i = 1;
	while (av[i])
	{
		if (!av[i + 1])
		{
			printf("%s", av[i++]);
			break ; 
		}
		printf("%s, ", av[i++]);
	}
	ft_createstacka(av, &a);
	t_list *cur = a;
	printf("\n");
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	ft_lstclear(&a, free);
	return (0);
}
