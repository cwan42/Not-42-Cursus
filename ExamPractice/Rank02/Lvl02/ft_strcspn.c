/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:56:49 by cwan              #+#    #+#             */
/*   Updated: 2023/11/23 15:23:59 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	printf("Real strcspn: %lu\nft_strcspn:  %lu\n", strcspn(av[1], av[2]),
	ft_strcspn(av[1], av[2]));
}*/

/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------
Reproduce exactly the behavior of the function strcspn
The function should be prototyped as follows:
size_t	ft_strcspn(const char *s, const char *reject);
SYNOPSIS
       #include <string.h>
       size_t strspn(const char *s, const char *accept);
       size_t strcspn(const char *s, const char *reject);

The strcspn() function calculates the length of the initial segment of s which consists entirely of bytes not in reject.
RETURN VALUE
The strcspn() function returns the number of bytes in the initial segment of s which are not in the string reject.*/
