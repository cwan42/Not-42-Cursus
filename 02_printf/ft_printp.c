/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:21:48 by cwan              #+#    #+#             */
/*   Updated: 2023/09/25 01:45:27 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hexconverter(unsigned long n, const char *cipher)
{
	int	i;

	i = 0;
	if (n < 16)
		i += write(1, &cipher[n], 1);
	else
	{
		i += hexconverter((n / 16), cipher);
		i += hexconverter((n % 16), cipher);
	}
	return (i);
}

int		ft_printp(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (0);
	else
	{
		len += write(1, "0x", 2);
		len += hexconverter(ptr, "0123456789abcdef");
	}
	return (len);
}
