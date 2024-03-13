/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/03/13 17:31:11 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inputcheck(char **av, t_stack **list)
{
	char	*wspace;
	char	*str;
	char	*tmpptr;
	char	**arr;
	int		i;

	str = ft_calloc(1, sizeof(char *));
	*list = NULL;
	av++;
	while (*av)
	{
		tmpptr = str;
		wspace = ft_strjoin(*av++, " ");
		str = ft_strjoin(str, wspace);
		(void)(free(wspace), free(tmpptr));
	}
	tmpptr = str;
	while ((*str >= '0' && *str <= '9') || *str == ' ' || *str == '\n')
		str++;
	if (*str)
		return (free(tmpptr), 1);
	arr = ft_split((tmpptr), ' ');
	i = 0;
	while (arr[i])
		ft_stkadd_back(list, ft_stknew(ft_atoi(arr[i++])));
	return (free(tmpptr), ft_free(arr), 0);
}

//	ARRAY test for duplicates, MININT/MAXINT
void	printloops(t_stack **list, t_stack **listb)
{
	t_stack	*head;
	t_stack	*headb;

	if (*list)
	{
		head = *list;
		while (head->next != *list)
		{
			ft_printf("%d ", head->num);
			head = head->next;
		}
		ft_printf("%d.\t", head->num);
	}
	if (*listb)
	{
		headb = *listb;
		while (headb->next != *listb)
		{
			ft_printf("%d ", headb->num);
			headb = headb->next;
		}
		ft_printf("%d.\n", headb->num);
	}
}

#include <stdio.h>

int	main(int ac, char *av[])
{
	t_stack	**stacka;
	t_stack	**stackb;

	stacka = malloc(sizeof(t_stack *));
	stackb = malloc(sizeof(t_stack *));
	*stackb = NULL;
	if (ac > 1 && stacka && stackb)
		if (inputcheck(av, stacka))
			return (ft_putstr_fd("Error\n", 2), ft_freestack(stacka), \
			free(stackb), 1);
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
	}*/
	printloops(stacka, stackb);
	return (ft_freestack(stacka), free(stackb), 0);
}
