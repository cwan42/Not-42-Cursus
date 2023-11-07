/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:13:39 by cwan              #+#    #+#             */
/*   Updated: 2023/10/20 15:41:25 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>

int	main(void)
{
	int	num1 = 123456789;
	int	num2 = 987654321;

	printf("Before: %d, %d\n", num1, num2);
	ft_swap(&num1, &num2);
	printf("After:  %d, %d\n", num1, num2);
}

/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------
Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.
Your function must be declared as follows:
void	ft_swap(int *a, int *b);
*/
