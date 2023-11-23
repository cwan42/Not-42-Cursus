/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:09:51 by cwan              #+#    #+#             */
/*   Updated: 2023/11/22 13:15:21 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	return(strcmp(s1, s2));
}

#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	printf("Real strcmp: %d\nft_strcmp:  %d\n", strcmp(av[1], av[2]), ft_strcmp(av[1], av[2]));
}
/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions: 
--------------------------------------------------------------------------------
Reproduce the behavior of the function strcmp (man strcmp).
Your function must be declared as follows:
int    ft_strcmp(char *s1, char *s2);

strcmp() returns an integer indicating the result of the comparison, as follows:
       • 0, if the s1 and s2 are equal;
       • a negative value if s1 is less than s2;
       • a positive value if s1 is greater than s2.
*/
