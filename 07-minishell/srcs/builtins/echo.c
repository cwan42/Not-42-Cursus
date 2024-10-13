/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:00:14 by cwan              #+#    #+#             */
/*   Updated: 2024/09/19 11:01:35 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_n_flag(const char *str)
{
	int	i;

	i = 2;
	if (str[0] != '-' || str[1] != 'n')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(t_cmd *tab)
{
	int		i;
	char	**arr;
	int		newline;

	i = 1;
	newline = 1;
	arr = tab->cmds;
	while (arr[i] && is_valid_n_flag(arr[i]))
	{
		newline = 0;
		i++;
	}
	while (arr[i])
	{
		if (arr[i] && arr[i][0])
		{
			printf("%s", arr[i]);
			if (arr[i + 1])
				printf(" ");
		}
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}
