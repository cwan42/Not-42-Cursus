/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:21:48 by cwan              #+#    #+#             */
/*   Updated: 2023/09/21 10:28:21 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hexconverter(unsigned long n, char *cipher)
{
	unsigned int	i;

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
	int	i;

	i = 0;
	if (!ptr)
	{
		ft_prints("NO PTR");
		return (0);
	}
	else
	{
		i += write(1, "0x", 2);
		i += hexconverter(ptr, "0123456789abcdef");
	}
	return (i);
}
