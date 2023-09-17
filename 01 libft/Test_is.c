/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:38:27 by cwan              #+#    #+#             */
/*   Updated: 2023/09/17 15:03:06 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	main(void)
{
	char	*str;
	int		i;

	str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 123~!@#\0\t\r";
	i = 0;
	printf("%s", "\nValue actual: ");
	while (str[i])
	{
		printf("%c", str[i++]);
	}
	i = 0;
	printf("%s", "\n\nft_isalpha: ");
	while (str[i])
	{
		if ((ft_isalpha(str[i]) != 0) && (isalpha(str[i]) != 0))
			printf("%s ", "OK");
		if ((ft_isalpha(str[i]) == 0) && (isalpha(str[i]) == 0))
			printf("%s ", "OK");
		if ((ft_isalpha(str[i])) == 0 && (isalpha(str[i]) != 0))
			printf("%c ", 'F');
		if ((ft_isalpha(str[i])) != 0 && (isalpha(str[i]) == 0))
			printf("%c ", 'F');
		i++;
	}
	printf("%s", "\n\nft_isascii: ");
	i = 0;
	while (str[i])
	{
		if ((ft_isascii(str[i]) != 0) && (isascii(str[i]) != 0))
			printf("%s ", "OK");
		if ((ft_isascii(str[i]) == 0) && (isascii(str[i]) == 0))
			printf("%s ", "OK");
		if ((ft_isascii(str[i]) == 0) && (isascii(str[i]) != 0))
			printf("%s ", "F");
		if ((ft_isascii(str[i]) != 0) && (isascii(str[i]) == 0))
			printf("%s ", "F");
		i++;
	}
	printf("%s", "\n\nft_isalnum: ");
	i = 0;
	while (str[i])
	{
		if ((ft_isalnum(str[i]) != 0) && (isalnum(str[i]) != 0))
			printf("%s ", "OK");
		if ((ft_isalnum(str[i]) == 0) && (isalnum(str[i]) == 0))
			printf("%s ", "OK");
		if ((ft_isalnum(str[i]) == 0) && (isalnum(str[i]) != 0))
			printf("%s ", "F");
		if ((ft_isalnum(str[i]) != 0) && (isalnum(str[i]) == 0))
			printf("%s ", "F");
		i++;
	}
	printf("%s", "\n\nft_isdigit: ");
	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) != 0) && (isdigit(str[i]) != 0))
			printf("%s ", "OK");
		if ((ft_isdigit(str[i]) == 0) && (isdigit(str[i]) == 0))
			printf("%s ", "OK");
		if ((ft_isdigit(str[i]) == 0) && (isdigit(str[i]) != 0))
			printf("%s ", "F");
		if ((ft_isdigit(str[i]) != 0) && (isdigit(str[i]) == 0))
			printf("%s ", "F");
		i++;
	}
	printf("%s", "\n\nft_isprint: ");
	i = 0;
	while (str[i])
	{
		if ((ft_isprint(str[i]) != 0) && (isprint(str[i]) != 0))
			printf("%s ", "OK");
		if ((ft_isprint(str[i]) == 0) && (isprint(str[i]) == 0))
			printf("%s ", "OK");
		if ((ft_isprint(str[i]) == 0) && (isprint(str[i]) != 0))
			printf("%s ", "F");
		if ((ft_isprint(str[i]) != 0) && (isprint(str[i]) == 0))
			printf("%s ", "F");
		i++;
	}
	printf("%s", "\n\nft_toupper: ");
	i = 0;
	while (str[i])
	{
		if ((ft_toupper(str[i]) == toupper(str[i])))
			printf("%s ", "OK");
		else
			printf("%s ", "F");
		i++;
	}
	printf("%s", "\n\nft_tolower: ");
	i = 0;
	while (str[i])
	{
		if ((ft_tolower(str[i]) == tolower(str[i])))
			printf("%s ", "OK");
		else
			printf("%s ", "F");
		i++;
	}
	printf("%s", "\n\n");
	return (0);
}
