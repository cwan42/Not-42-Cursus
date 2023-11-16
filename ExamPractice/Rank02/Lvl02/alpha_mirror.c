/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:56:12 by cwan              #+#    #+#             */
/*   Updated: 2023/11/16 14:20:39 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;

	i = 0;
	while (ac == 2 && av[1][i])
	{
		if ((av[1][i] >= 'A' && av[1][i] <= 'M')


		else if ((av[1][i] >= 'N' && av[1][i] <= 'Z') || (av[1][i] >= 'n' && 
			av[1][i] <= 'z'))
		write(1, &av[1][i], 1);
	}
	write (1, "\n", 1);
}

/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
and so on.
Case is not changed.
If the number of arguments is not 1, display only a newline.
Examples:
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/
