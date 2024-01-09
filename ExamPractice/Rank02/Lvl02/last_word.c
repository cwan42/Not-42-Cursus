/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:45:29 by cwan              #+#    #+#             */
/*   Updated: 2024/01/09 15:11:44 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Solulu 1
#include <unistd.h>

int	main(int ac, char *av[])
{
	int		i;

	i = 0;
	while (ac == 2 && av[1][i])
		i++;
	i--;
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i--;
	while (av[1][i -1] != ' ' && av[1][i - 1] != '\t' && i >= 0)
		i--;
	while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
	{
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}*/

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i = 0;
	while (ac == 2 && av[1][i])
		i++;
	i--;
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i--;
	while (av[1][i - 1] != ' ' && av[1][i - 1] != '\t' && i >= 0)
		i--;
	while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
		write(1, &av[1][i++], 1);
	return (write(1, "\n", 1), 0);
}

/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays its last word followed by a \n.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or there are no words, display a newline.
Example:
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$> */
