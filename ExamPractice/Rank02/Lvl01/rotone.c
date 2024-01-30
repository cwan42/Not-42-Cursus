/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:58:50 by cwan              #+#    #+#             */
/*   Updated: 2024/01/30 15:20:15 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'y')
				av[1][i] += 1;
			else if (av[1][i] >= 'A' && av[1][i] <= 'Y')
				av[1][i] += 1;
			else if (av[1][i] == 'z' || av[1][i] == 'Z')
				av[1][i] -= 25;
			write(1, &av[1][i++], 1);
		}
	}
	return(write(1, "\n", 1), 0);
}

/* Solulu 02
int	main(int ac, char *av[])
{
	int	i;

	i = 0;
	while (ac == 2 && av[1][i])
	{
		if ((av[1][i] > 64 && av[1][i] < 90) || (av[1][i] > 96 && av[1][i] < 122))
			av[1][i] += 1;
		else if (av[1][i] == 'z' || av[1][i] == 'Z')
			av[1][i] -= 25;
		write (1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}
/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.
'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
The output will be followed by a \n.
If the number of arguments is not 1, the program displays \n.
Example:
$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/
