/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:45:13 by cwan              #+#    #+#             */
/*   Updated: 2023/12/20 15:23:14 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_hcf(unsigned int a, unsigned int b)
{
	while (b)
	{
		unsigned int	tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	hcf = ft_hcf(a, b);
	unsigned int	lcm = (a * b) / hcf;
	return (lcm);
}
/*
#include <stdlib.h>

int	main(int ac, char *av[])
{
	if (ac == 3)
		printf("LCM of %s & %s is %d\n", av[1], av[2], lcm(atoi(av[1]), atoi(av[2])));
}
*/

/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.
LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.
A LCM can be calculated in two ways:
- You can calculate every multiples of each integers until you have a common
multiple other than 0
- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:
	LCM(x, y) = | x * y | / HCF(x, y)
  | x * y | means "Absolute value of the product of x by y"
If at least one integer is null, LCM is equal to 0.
Your function must be prototyped as follows:
  unsigned int    lcm(unsigned int a, unsigned int b); */
