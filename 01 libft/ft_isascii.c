/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:42:57 by cwan              #+#    #+#             */
/*   Updated: 2023/09/07 10:20:52 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	input;

	printf("Enter a character: ");
	scanf("%c", &input);
	printf("%d\n", ft_isascii(input));
	printf("%d\n", isascii(input));
}
*/
