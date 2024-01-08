/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:49:43 by cwan              #+#    #+#             */
/*   Updated: 2024/01/08 18:23:53 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return (char *)(s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	printf("Real strpbrk: %s\nft_strpbrk:   %s\n", strpbrk(av[1], av[2]),
	ft_strpbrk(av[1], av[2]));
}*/
/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------
Reproduce exactly the behavior of the function strpbrk
The function should be prototyped as follows:
char	*ft_strpbrk(const char *s1, const char *s2);

The strpbrk() function locates the first occurrence in the string s of any of
the bytes in the string accept.
RETURN VALUE
The strpbrk() function returns a pointer to the byte in s that matches one of
the bytes in accept, or NULL if no such byte is found. */
