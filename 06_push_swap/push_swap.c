/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/03/24 17:01:56 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printloops(t_stack **list, t_stack **listb)
{
	t_stack	*head;
	t_stack	*headb;

	if (*list)
	{
		head = *list;
		while (head->n != *list)
		{
			ft_printf("%d ", head->nu);
			head = head->n;
		}
		ft_printf("%d.\t", head->nu);
	}
	if (*listb)
	{
		headb = *listb;
		while (headb->n != *listb)
		{
			ft_printf("%d ", headb->nu);
			headb = headb->n;
		}
		ft_printf("%d.\n", headb->nu);
	}
	else
		ft_printf("nil.\n");
}

//#include <stdio.h>
int	main(int ac, char *av[])
{
	t_stack	**stacka;
	t_stack	**stackb;

	stacka = malloc(sizeof(t_stack *));
	*stacka = NULL;
	if (ac > 1)
	{
		if (procargv(av, stacka))
			return (ft_putstr_fd("Error\n", 2), free(stacka), 1);
	}
	else
		return (free(stacka), 0);
	stackb = malloc(sizeof(t_stack *));
	*stackb = NULL;
	initpri(stacka, stackb);
	if (stacka && stackb)
		printloops(stacka, stackb);
	if (!*stacka)
		return (free(stacka), free(stackb), 1);
	return (ft_freestack(stacka), free(stackb), 0);
}

/*	char	str[4];
	ft_printf("Enter a valid operation (sa, sb, ss, pa, pb, ra, rb, rr, rra,");
	ft_printf(" rrb, rrr) or type END to exit: \n");
	printloops(stacka, stackb);
	while (1)
	{
		scanf("%4s", str);
		if (ft_strncmp(str, "END", 4) == 0)
			break ;
		else if (ft_strncmp(str, "pa", 3) == 0)
			pa(stacka, stackb);
		else if (ft_strncmp(str, "pb", 3) == 0)
			pb(stacka, stackb);
		else if (ft_strncmp(str, "sa", 3) == 0)
			sa(stacka);
		else if (ft_strncmp(str, "sb", 3) == 0)
			sb(stackb);
		else if (ft_strncmp(str, "ss", 3) == 0)
			ss(stacka, stackb);
		else if (ft_strncmp(str, "ra", 3) == 0)
			ra(stacka);
		else if (ft_strncmp(str, "rb", 3) == 0)
			rb(stackb);
		else if (ft_strncmp(str, "rr", 3) == 0)
			rr(stacka, stackb);
		else if (ft_strncmp(str, "rra", 4) == 0)
			rra(stacka);
		else if (ft_strncmp(str, "rrb", 4) == 0)
			rrb(stackb);
		else if (ft_strncmp(str, "rrr", 4) == 0)
			rrr(stacka, stackb);
		printloops(stacka, stackb);
	}
	if (stacka && stackb)
		printloops(stacka, stackb);
	if (!*stacka)
		return (free(stacka), free(stackb), 1);
	return (ft_freestack(stacka), free(stackb), 0);
}*/
