/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/01/03 09:30:16 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_createstacka(char **av, t_stack **stack)
{
	t_stack *node;

	av++;
	while (*av)
	{
		node = ft_stacknew(ft_atoi(*av));
		if (!node)
			break ;
		ft_stackadd_back(stack, node);
		av++;
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

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
			printf("%s\n", av[i++]);
			break ; 
		}
		printf("%s, ", av[i++]);
	}
	ft_createstacka(av, &a);
	t_stack *cur = a;
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
	return (0);
}
