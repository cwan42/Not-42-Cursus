/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:58:21 by cwan              #+#    #+#             */
/*   Updated: 2024/01/17 14:34:00 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

Solulu 1

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
	}
}
/*
Solulu 2

void	print_bits(unsigned char octet)
{
	int	i = 128;
	while (i)
	{
		if (octet & i)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i /= 2;
	}
}

Solulu 3

void	print_bits(unsigned char octet)
{
	int	i = 8;
	int	res = 0;

	while (i--)
		res = res * 10 + (octet >> i & 1);
	PRINTWIP
}

int	main(void)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		print_bits(0 + i);
		write(1 , " ", 1);
		i++;
	}
	return (0);
}
*/
/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void	print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010" */
