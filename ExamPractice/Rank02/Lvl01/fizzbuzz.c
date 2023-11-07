/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:41:26 by cwan              #+#    #+#             */
/*   Updated: 2023/10/20 14:02:13 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writenumber(int n)
{
	char	num;

	if (n > 9)
		writenumber(n / 10);
	num = '0' + n % 10;
	write (1, &num, 1);
	
}

void	main(void)
{
	int	i;

	i = 1;
	while (i < 101)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			writenumber(i);
	write(1, "\n", 1);
	i++;
	}
}

/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that prints the numbers from 1 to 100, each separated by a
newline.
If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.
Example:
$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/
