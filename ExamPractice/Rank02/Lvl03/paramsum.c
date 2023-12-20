/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:23:44 by cwan              #+#    #+#             */
/*   Updated: 2023/12/20 15:40:27 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int i = 0;
	char digit;

	if (ac < 2)
		return (write(1, "0\n", 2), 0);
	while (av[i])
		i++;
	i--;
	while (i > 0)
	{
		digit = '0' + i % 10;
		i /= 10;
		write(1, &digit, 1);
	}
	write(1, "\n", 1);
}

/*
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that displays the number of arguments passed to it, followed by
a newline.
If there are no arguments, just display a 0 followed by a newline.
Example:
$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$> */
