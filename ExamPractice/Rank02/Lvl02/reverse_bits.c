/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:07:26 by cwan              #+#    #+#             */
/*   Updated: 2023/12/04 12:31:13 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	rev;
	int				i;

	i = 8;
	rev = 0;
	while (i--)
	{
		rev = (rev << 1) | (octet & 1);
		octet >>= 1 ;
	}
	return (rev);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < 20)
	{
		printf("%d = %d\n", i, reverse_bits(i));
		i++;
	}
	printf("\n");
	return (0);
} */

/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.
Your function must be declared as follows:
unsigned char	reverse_bits(unsigned char octet);
Example:
  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/
