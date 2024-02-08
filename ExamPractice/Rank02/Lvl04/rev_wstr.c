/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:45:25 by cwan              #+#    #+#             */
/*   Updated: 2023/12/29 12:52:29 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i = 0;
	int	j;

	while (ac == 2)
	{
		while (av[1][i])
			i++;
		while (i > -1)
		{
			while (av[1][i] != ' ' && (i != 0))
				i--;
			j = i + 1;
			if (i == 0)
				j = i;
			while (av[1][j] != ' ' && av[1][j])
				write(1, &av[1][j++], 1);
			if (i != 0)
				write(1, " ", 1);
			if (i == 0)
				return (write(1, "\n", 1), 0);
			i--;
		}
	}
	return (write(1, "\n", 1), 0);
}

/* Solulu 02
#include <unistd.h>
#include <stdlib.h>

int	ft_wordcount(char *str)
{
	int words = 0;

	while (*str)
	{
		if (*str > 32)
		{
			words++;
			while (*str > 32)
				str++;
		}
		else
			str++;
	}
	return (words);
}

char	**ft_split(char *str)
{
	char	**array = malloc(sizeof(char *) * (ft_wordcount(str) +1));
	int		i = 0;
	int		j;

	while (*str)
	{
		if (*str > 32)
		{
			j = 0;
			array[i] = malloc(sizeof(char) * 100);
			while (*str > 32)
				array[i][j++] = *(str++);
		array[i][j] = '\0';
		i++;
		}
		else
			str++;
	}
	array[i] = 0;
	return (array);
}

#include <stdio.h>

int	main(int ac, char *av[])
{
	char	**array;
	int		i = 0;
	int		j;

	if (ac == 2)
	{
		array = ft_split(av[1]);
		while (array[i])
			i++;
		i--;
		while (i >= 0)
		{
			j = 0;
			while (array[i][j])
				write(1, &array[i][j++], 1);
			if (i > 0)
				write(1, " ", 1);
			i--;
		}
		i = 0;
		while (array[i])
			free(array[i++]);
		free(array);
	}
	write(1, "\n", 1);
	return (0);	
}*/
/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string as a parameter, and prints its words in 
reverse order.
A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.
If the number of parameters is different from 1, the program will display 
'\n'.
In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).
Examples:
$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$> */
