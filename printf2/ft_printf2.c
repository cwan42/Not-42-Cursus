/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:13:05 by cwan              #+#    #+#             */
/*   Updated: 2023/09/26 12:09:28 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
		i++;
	}
	else
	{
		if (n > 9)
			i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	return (i);
}

int	ft_putunsnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_printp(void *ptr)
{
	unsigned long	n;
	int				i;

	i = 0;
	if (!ptr)
		i += ft_putstr("0x0");
	else
	{
		n = (unsigned long)ptr;
		i += ft_putstr("0x");
		i += ft_hexconv(n);
	}
	return (i);
}
