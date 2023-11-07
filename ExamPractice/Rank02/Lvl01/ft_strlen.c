/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:10:45 by cwan              #+#    #+#             */
/*   Updated: 2023/10/20 15:13:10 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>

int	main(void)
{
	printf("String length of \"Poop on a string\" is:%d", ft_strlen("Poop on a string"));
}

/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions: 
--------------------------------------------------------------------------------
Write a function that returns the length of a string.
Your function must be declared as follows:
int	ft_strlen(char *str);
*/
