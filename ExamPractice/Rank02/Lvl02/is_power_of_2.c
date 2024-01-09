/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:11:20 by cwan              #+#    #+#             */
/*   Updated: 2024/01/09 14:42:11 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	return (n == 1);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 1;
	while (i < 8193)
	{
		if (is_power_of_2(i))
			printf("\33[32m%d \033[0m", i);
		else
		{
			if (!is_power_of_2(i) && i > 1000)
				printf("\33[31m.\033[0m");
			else
				printf("\33[31m%d \033[0m", i);
		}
		i++;
	}
	return (0);
}*/

/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------
Write a function that determines if a given number is a power of 2.
This function returns 1 if the given number is a power of 2, otherwise it returns 0.
Your function must be declared as follows:
int	    is_power_of_2(unsigned int n); */
