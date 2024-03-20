/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-Inputvalidatn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/03/20 21:40:59 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkvalid(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = 1;
		if ((!(arr[i][0] >= '0' && arr[i][0] <= '9') && arr[i][0] != '-') ||
		(arr[i][0] == '-' && !arr[i][1]) ||
		(arr[i][0] == '-' && !(arr[i][1] >= '0' && arr[i][1] <= '9')))
			return (1);
		while (arr[i][j])
		{
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	checkmaxmin(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if ((ft_atol(arr[i]) > 2147483647) || (ft_atol(arr[i]) < -2147483648))
			return (1);
		i++;
	}
	return (0);
}

static int	checkdup(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (!ft_strcmp(arr[i], arr[j]) && (i != j))
				return (1);
			j++;
		}
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
	if (*str || checkvalid(arr) || checkmaxmin(arr) || checkdup(arr))
		return (free(tmpptr), ft_free(arr), 1);
	tmpptr2 = arr;
	while (*arr)
		ft_stkadd_back(stacka, ft_stknew(ft_atoi(*arr++)));
	return (free(tmpptr), ft_free(tmpptr2), 0);
}
