/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:53:17 by cwan              #+#    #+#             */
/*   Updated: 2023/12/04 12:59:27 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return  ((octet >> 4) | (octet << 4));
}
/*
#include <stdio.h>

int	main(void)
{
	int	i = 0;

	while (i < 24)
	{
		printf("%d to %d\n", i, swap_bits(i));
		i++;
	}
	return (0);
}
*/
/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.
Your function must be declared as follows:
unsigned char	swap_bits(unsigned char octet);
Example:
  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/
