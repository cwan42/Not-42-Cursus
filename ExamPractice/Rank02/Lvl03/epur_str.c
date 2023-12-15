/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:34:43 by cwan              #+#    #+#             */
/*   Updated: 2023/12/15 12:07:23 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if ((av[1][i] == '\t' || av[1][i] == ' '))
			{
				if (av[1][i + 1] > 32)
					write(1, " ", 1);
			}
			else if (av[1][i] != ' ' && av[1][i] != '\t')
					write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
If the number of arguments is not 1, or if there are no words to display, the
program displays \n.
Example:
$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$> */
