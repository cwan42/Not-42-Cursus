/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:45:58 by cwan              #+#    #+#             */
/*   Updated: 2024/01/16 18:09:32 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	int	i = 0;
	int	j;
	int	firstword = 0;

	if (ac >= 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		j = i;
		while (av[1][i] > 32)
			i++;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] > 32)
			{
				write(1, &av[1][i], 1);
				firstword = 1;
			}
			if ((av[1][i] < 33) && (av[1][i - 1] > 32) && av[1][i + 1])
				write(1, &av[1][i], 1);
			i++;
		}
		if (firstword)
			write(1, " ", 1);
		while (av[1][j] > 32)
				write(1, &av[1][j++], 1);

	}
	return (write(1, "\n", 1), 0);
}
/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string and displays this string after rotating it
one word to the left.
Thus, the first word becomes the last, and others stay in the same order.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
Words will be separated by only one space in the output.
If there's less than one argument, the program displays \n.
Example:
$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring | cat -e
$
$> */
