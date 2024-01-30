/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:16:53 by cwan              #+#    #+#             */
/*   Updated: 2024/01/30 14:05:39 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	simpleatoi(char *str)
{
	int	i = 0;
	int	res = 0;

	while (str[i])
		res = (res * 10) + (str[i++] - '0');
	return (res);
}

void	hexconv(int n)
{
	if (n > 15)
	{
		hexconv(n / 16);
		hexconv(n % 16);
	}
	if (n < 10)
		ft_putchar(n + '0');
	else if (n < 16)
		ft_putchar(n - 10 + 'a');
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		hexconv(simpleatoi(av[1]));
	}
	return (write(1, "\n", 1), 0);
}

/* Solulu 02

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ft_hexconv(int n)
{
	if (n > 15)
	{
		ft_hexconv(n / 16);
		ft_hexconv(n % 16);
	}
	if (n < 10)
		ft_putchar(n + 48);
	else if (n < 16)
		ft_putchar(n + 87);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		ft_hexconv(ft_atoi(av[1]));
	}
	return (ft_putchar('\n'), (0));
} */

/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.
If the number of parameters is not 1, the program displays a newline.
Examples:
$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$ */
