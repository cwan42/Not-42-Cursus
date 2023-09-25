/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:21:48 by cwan              #+#    #+#             */
/*   Updated: 2023/09/25 15:14:13 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexer(unsigned long n)
{
	int	i;

	i = 0;
	if (n > 15)
		i += hexer(n / 16);
	ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	i++;
	return (i);
}

int	ft_printp(void *ptr)
{
	int				len;
	unsigned long	n;

	len = 0;
	if (!ptr)
		len += write(1, "0x0", 3);
	else
	{
		n = (unsigned long)ptr;
		len += write(1, "0x", 2);
		len += hexer(n);
	}
	return (len);
}

int	ft_printu(unsigned int n)
{
	int		i;

	i = 0;
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
		i++;
	}
	ft_putchar_fd('0' + n % 10, 1);
	i++;
	return (i);
}
