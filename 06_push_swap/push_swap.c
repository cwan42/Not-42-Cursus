/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/01/03 10:16:46 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_createstacka(char **av, t_stack **stack, int ac)
{
	t_stack *node;

	if (ac != 2)
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
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_createstacka(av, &a, ac);
	t_stack *cur = a;
	while (cur)
	{
		ft_printf("%d ", cur->value);
		cur = cur->next;
	}
	ft_printf("\n");
	return (0);
}
