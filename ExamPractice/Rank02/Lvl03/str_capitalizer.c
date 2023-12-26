/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:49:23 by cwan              #+#    #+#             */
/*   Updated: 2023/12/26 13:27:05 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_toupper(char c, char d)
{
	if (c >= 'a' && c <= 'z')
	{
		if (d == '\t' || d == ' ')
			return (1);
	}
	return (0);
}

int	ft_tolower(char c, char d)
{
	if (c >= 'A' && c <= 'Z')
	{
		if (d != '\t' && d != ' ')
			return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	int	args = 1;
	int	i;

	if (ac > 1)
	{
		while (args < ac)
		{
			i = 0;
			while (av[args][i])
			{
				if (av[args][0] >= 'a' && av[args][0] <= 'z')
					av[args][0] -= 32;
				else if (ft_toupper(av[args][i], av[args][i - 1]) && i > 0)
					av[args][i] -= 32;
				else if (ft_tolower(av[args][i], av[args][i - 1]) && i > 0)
					av[args][i] += 32;
				write(1, &av[args][i], 1);
				i++;
			}
			write(1, "\n", 1);
			args++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.
If there are no arguments, the progam must display \n.
Example:
$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$> */
