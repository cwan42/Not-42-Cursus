/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:47:39 by cwan              #+#    #+#             */
/*   Updated: 2023/12/26 12:48:20 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_toupper(char c, char d)
{
	if (c >= 'a' && c <= 'z')
	{
		if (d == '\t' || d == ' ' || !d)
			return (1);
	}
	return (0);
}

int	ft_tolower(char c, char d)
{
	if (c >= 'A' && c <= 'Z')
	{
		if (d != '\t' && d != ' ' && d)
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
				if (ft_toupper(av[args][i], av[args][i + 1]))
					av[args][i] -= 32;
				else if (ft_tolower(av[args][i], av[args][i + 1]))
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
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes one or more strings and, for each argument, puts 
the last character of each word (if it's a letter) in uppercase and the rest
in lowercase, then displays the result followed by a \n.
A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.
If there are no parameters, display \n.
Examples:
$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "Premier PETIT TesT" | cat -e
premieR petiT tesT$
$> ./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
deuxiemE tesT uN peU moinS  facilE$
   attentioN c'esT paS duR quanD memE$
alleR uN dernieR 0123456789pouR lA routE    E $
$> */
