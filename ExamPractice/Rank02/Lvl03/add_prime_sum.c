/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:56:35 by cwan              #+#    #+#             */
/*   Updated: 2024/01/17 17:01:32 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Solulu 1

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	sign = 1;
	int	res = 0;

	while (str[i] < 33)
		i++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_isprime(int n)
{
	int	i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int	n;
	int sum = 0;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		while (n)
		{
			if (ft_isprime(n))
				sum += n;
			n--;
		}
		ft_putnbr(sum);
	}
	return (write(1, "\n", 1), 0);
}
/* Solulu 2

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}	

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (long)(sign * res);
}

long	ft_isprime(long n)
{
	int	i;

	if (n < 2 || (n > 2 && !(n % 2)))
		return (0);
	if (n == 2)
		return (1);
	i = 3;
	while (i * i <= n)
	{
		if (!(n % i))
			return (0);
		i += 2;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int		i;
	long	res;
	long	num;

	i = 0;
	res = 0;
	if (av[1])
		num = ft_atoi(av[1]);
	if (ac != 2 || num < 0)
		return  (write(1, "0\n", 2), 0);
	while (i <= num)
	{
		if (ft_isprime(i))
			res += i;
		i++;
	}
	ft_putnbr(res);
	ft_putchar('\n');
}
*/
/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------
Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.
If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.
Yes, the examples are right.
Examples:
$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$> */
