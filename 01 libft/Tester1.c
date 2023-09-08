/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:24:10 by cwan              #+#    #+#             */
/*   Updated: 2023/09/07 12:16:44 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>

// TEST PROG FOR isascii, isalpha, isalnum, isdigit, isprint, tolower, to upper
int	main(void)
{
	char	input;

	printf("Enter a char: ");
	scanf("%c", &input);
	printf("%c is ascii:%d,%d\n", input, ft_isascii(input), isascii(input));
	printf("%c is alpha:%d,%d\n", input, ft_isalpha(input), isalpha(input));
	printf("%c is digit:%d,%d\n", input, ft_isdigit(input), isdigit(input));
	printf("%c is alnum:%d,%d\n", input, ft_isalnum(input), isalnum(input));
	printf("%c is print:%d,%d\n", input, ft_isprint(input), isprint(input));
	printf("%c to lower:%c,%c\n", input, ft_tolower(input), tolower(input));
	printf("%c to upper:%c,%c\n", input, ft_toupper(input), toupper(input));
}