/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:32:05 by cwan              #+#    #+#             */
/*   Updated: 2023/09/11 10:25:44 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

// TEST PROG FOR atoi, strlen, memset, bzero
int	main(void)
{
	char	string[200];
	size_t	len;

	printf("Enter a sentence: ");
	scanf("%199s", string);
	len = ft_strlen(string);
	printf("Orig: %s, ft_strlen=%lu\n", string, len);
	printf("atoi: %i\n", ft_atoi(string));
	printf("ft_memset: %s\n", (char *)ft_memset(string, 'A', len));
	printf("memset: %s\n", (char *)memset(string, 'B', len));
	ft_bzero(string, len);
	printf("bzero: %sEOL\n", string);
}
