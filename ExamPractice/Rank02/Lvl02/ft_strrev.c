/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:37:27 by cwan              #+#    #+#             */
/*   Updated: 2023/11/24 16:53:08 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (i > j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i--;
		j++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		printf("Real string: %s\n", av[1]);
		printf("ft_strrev:  %s\n", ft_strrev(av[1]));
	}
}*/
/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------
Write a function that reverses (in-place) a string.
It must return its parameter.
Your function must be declared as follows:
char    *ft_strrev(char *str);*/
