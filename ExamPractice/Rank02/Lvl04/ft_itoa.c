/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:43:08 by cwan              #+#    #+#             */
/*   Updated: 2023/12/28 12:21:33 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_intlen(int n)
{
	int	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i = ft_intlen(nbr);
	int		n;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	n = nbr;
	if (nbr < 0)
		n = -nbr;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (nbr < 0)
		str[i] = '-';
	return (str);
}
/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	int	num;

	if (ac != 2)
		return (0);
	num = atoi(av[1]);
	printf("Number is %d, ", num);
	char	*str = ft_itoa(num);
	printf("after itoa is %s\n", str);
	return (free(str), 0);
}
*/
/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.
Your function must be declared as follows:
char	*ft_itoa(int nbr); */
