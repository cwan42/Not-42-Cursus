/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:44:58 by cwan              #+#    #+#             */
/*   Updated: 2023/12/28 11:52:20 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str)
{
	int		i = 0;
	int		j = 0;
	int		k;
	char	**array = (malloc(sizeof(**array) * 100));

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] > 32)
		{
			k = 0;
			array[j] = malloc(sizeof(char) * 100);
			while (str[i] > 32)
				array[j][k++] = str[i++];
		array[j][k] = '\0';
		j++;
		}
		else
			i++;
	}
	array[j] = 0;
	return (array);
}
/*
#include <stdio.h>

int	main(int ac, char *av[])
{
	char	**array;
	int 	i = 0;

	if (ac == 2)
		array = ft_split(av[1]);
	else
		return (0);
	while (array[i])
	{
		if (!array[i + 1])
		{
			printf("%s.\n", array[i]);
			break ;
		}
		printf("%s, ", array[i]);
		i++;
	}
	i = 0;
	while (array[i])
		free(array[i++]);
	return (free(array), 0);
}
*/
/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.
A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.
Your function must be declared as follows:
char    **ft_split(char *str); */
