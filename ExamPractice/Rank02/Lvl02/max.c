/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:29:04 by cwan              #+#    #+#             */
/*   Updated: 2024/01/09 15:25:12 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Solulu 1
int	max(int* tab, unsigned int len)
{
	int				maximum;
	unsigned int	i;

	i = 0;
	maximum = tab[i];
	while (i < len)
	{
		if (tab[i] > maximum)
			maximum = tab[i];
		i++;
	}
	return (maximum);
}*/

int	max(int* tab, unsigned int len)
{
	int				max = tab[0];

	while (--len > 0)
	{
		if (tab[len] > max)
			max = tab[len];
	}
	return (max);
}
/*
#include <stdio.h>

int	main(void)
{
	int				tab[] = {6, 1, 3, 5, 4, 9, 2, 7, 10, 8};
	unsigned int	len;
	unsigned int	i;

	len = sizeof(tab) / sizeof(tab[0]);
	i = 0;
	printf("For array of ");
	while (i < len)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf(", the largest number is: %d\n", max(tab, len));
	return (0);
}*/

/*
Assignment name  : max
Expected files   : max.c
Allowed functions: 
--------------------------------------------------------------------------------
Write the following function:
int		max(int* tab, unsigned int len);
The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.
If the array is empty, the function returns 0. */
