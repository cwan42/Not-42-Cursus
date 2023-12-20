/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:35:53 by cwan              #+#    #+#             */
/*   Updated: 2023/12/20 10:51:23 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int start, int end)
{
	int	i = 0;

	if (start <= end)
	{
		while (start <= end)
		{
			i++;
			start++;
		}
	}
	else
	{
		while (start >= end)
		{
			i++;
			start--;
		}
	}
	return (i);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * (ft_abs(start, end)));
	if (start <= end)
	{
		while (start <= end)
			arr[i++] = start++;
	}
	else if (start >= end)
	{
		while (start >= end)
			arr[i++] = start--;
	}
	return (arr);
}

/*
#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac != 3)
		return (1);
	int	*arr = ft_range(atoi(av[1]), atoi(av[2]));
	int	*arrptr = arr;
	int	i = 0;
	while (i < ft_abs(atoi(av[1]), atoi(av[2])))
	{
		printf("%d ", *arrptr++);
		i++;
	}
	return (free(arr), 0);
} */

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int     *ft_range(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.
Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */
