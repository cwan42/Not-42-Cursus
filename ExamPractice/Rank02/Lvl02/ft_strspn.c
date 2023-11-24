/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:53:40 by cwan              #+#    #+#             */
/*   Updated: 2023/11/24 17:05:43 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i] == accept[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	printf("Real strspn: %zu\nft_strspn:  %zu\n", strspn(av[1], av[2]),
	ft_strspn(av[1], av[2]));
}*/
/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------
Reproduce exactly the behavior of the strspn function 
(man strspn).
The function should be prototyped as follows:
size_t	ft_strspn(const char *s, const char *accept);
SYNOPSIS
       #include <string.h>
       size_t strspn(const char *s, const char *accept);
DESCRIPTION
       The  strspn()  function  calculates  the  length (in bytes) of the initial segment of s
       which consists entirely of bytes in accept.
RETURN VALUE
       The  strspn()  function  returns  the number of bytes in the initial segment of s which
       consist only of bytes from accept.*/
