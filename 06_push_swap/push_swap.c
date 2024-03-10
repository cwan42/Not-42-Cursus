/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/03/08 11:13:46 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printloops(t_stack **list, t_stack **listb)
{
	t_stack	*head = *list;
	t_stack	*headb = *listb;

	if (*list)
	{
		while (head->next != *list)
		{
			ft_printf("%d ", head->num);
			head = head->next;
		}
		ft_printf("%d.\t", head->num);
	}
	if (*listb)
	{
		while (headb->next != *listb)
		{
			ft_printf("%d ", headb->num);
			headb = headb->next;
		}
		ft_printf("%d.\n", headb->num);
	}
}

#include <stdio.h>

int	main(void)
{
	t_stack	**list = NULL;
	t_stack	**listb = NULL;
	int		i = 1;
	char	str[4];

	list = malloc(sizeof(t_stack *));
	listb = malloc(sizeof(t_stack *));
	if (!list || !listb)
		return (1);
	*list = NULL;
	*listb = NULL;
	while (i < 6)
		ft_stkadd_back(list, ft_stknew(i++));
	while (i < 11)
		ft_stkadd_back(listb, ft_stknew(i++));
	ft_printf("Enter a valid operation (sa, sb, ss, pa, pb, ra, rb, rr, rra,");
	ft_printf(" rrb, rrr) or type END to exit: \n");
	printloops(list, listb);
	while (1)
	{
		scanf("%4s", str);
		if (ft_strncmp(str, "END", 4) == 0)
			break ;
		else if (ft_strncmp(str, "pa", 3) == 0)
			pa(list, listb);
		else if (ft_strncmp(str, "pb", 3) == 0)
			pb(list, listb);
		else if (ft_strncmp(str, "sa", 3) == 0)
			sa(list);
		else if (ft_strncmp(str, "sb", 3) == 0)
			sb(listb);
		else if (ft_strncmp(str, "ss", 3) == 0)
			ss(list, listb);
		else if (ft_strncmp(str, "ra", 3) == 0)
			ra(list);
		else if (ft_strncmp(str, "rb", 3) == 0)
			rb(listb);
		else if (ft_strncmp(str, "rr", 3) == 0)
			rr(list, listb);
		else if (ft_strncmp(str, "rra", 4) == 0)
			rra(list);
		else if (ft_strncmp(str, "rrb", 4) == 0)
			rrb(listb);
		else if (ft_strncmp(str, "rrr", 4) == 0)
			rrr(list, listb);
		printloops(list, listb);
	}
	ft_freestack(list);
	ft_freestack(listb);
	return (0);
}
