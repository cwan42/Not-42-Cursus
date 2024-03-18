/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/03/18 10:47:16 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkmaxmin(char **arr)
{
	int		i;
	int		j;
	
	i = 0;
	while (arr[i])
	{
		j = 1;
		if (!(arr[i][0] >= '0' && arr[i][0] <= '9') && arr[i][0] != '-')
			return (1);
		if (arr[i][0] == '-' && !arr[i][1])
			return (1);
		if (arr[i][0] == '-' && !(arr[i][1] >= '0' && arr[i][1] <= '9'))
			return (1);
		while (arr[i][j])
		{
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (arr[i])
	{
		if ((ft_atoi(arr[i]) > 2147483647) || (ft_atoi(arr[i]) < -2147483648))
			return (1);
		i++;
	}
	return (0);
}

int	checkdup(char **arr)
{
	int	i;

	i = 0;
	while (arr[i + 1])
	{
		if (!ft_strcmp(arr[i], arr[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	procargv(char **av, t_stack **stacka)
{
	char	*wspace;
	char	*str;
	char	*tmpptr;
	char	**tmpptr2;
	char	**arr;

	str = ft_calloc(1, sizeof(char *));
	av++;
	while (*av)
	{
		tmpptr = str;
		wspace = ft_strjoin(*av++, " ");
		str = ft_strjoin(str, wspace);
		(void)(free(wspace), free(tmpptr));
	}
	tmpptr = str;
	while (ft_isdigit(*str) || *str == ' ' || *str == '-' || *str == '\n')
		str++;
	arr = ft_split(tmpptr, ' ');
	if (*str || checkmaxmin(arr) || checkdup(arr))
		return (free(tmpptr), ft_free(arr), 1);
	tmpptr2 = arr;
	while (*arr)
		ft_stkadd_back(stacka, ft_stknew(ft_atoi(*arr++)));
	return (free(tmpptr), ft_free(tmpptr2), 0);
}

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
/*	if (ac > 1)
		if (inputcheck(av, stacka))
			return (ft_putstr_fd("Error\n", 2), free(stacka), \
			free(stackb), 1);*/
	char	str[4];
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
}
