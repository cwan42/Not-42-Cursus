/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:15:19 by cwan              #+#    #+#             */
/*   Updated: 2024/01/17 17:44:26 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Solulu WIP
int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	sign = 1;
	int	res = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] > 32)
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		i++;
	}
	return (res * sign);
}

#include <stdio.h>

int	main(int ac, char *av[])
{
	char *str = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.";
	if (ac == 2 || av[0])
		printf("%d\n", ft_atoi_base(str, 16));
}

/* Solulu 2
int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			res += str[i] - 55;
		else if (str[i] >= 'a' && str[i] <= 'z')
			res += str[i] - 87;
		i++;
	}
	return (res * sign);
}

#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac == 2)
		printf("%d", ft_atoi_base(av[1], 16));
}*/
/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.
The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
Minus signs ('-') are interpreted only if they are the first character of the
string.
Your function must be declared as follows:
int	ft_atoi_base(const char *str, int str_base); */
