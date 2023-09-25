/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:53:15 by cwan              #+#    #+#             */
/*   Updated: 2023/09/25 15:14:42 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_formatspec(const char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_printp(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_printu(va_arg(args, unsigned int));
	else if (c == 'x')
		hexer(va_arg(args, unsigned long));
	else if (c == 'X')
		ft_toupper(hexer(va_arg(args, unsigned long)));
	else
		ft_putchar_fd('%', 1);
}

static int	validformat(const char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "cspdiuxX%";
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%' && validformat(str[i + 1]))
		{
			ft_formatspec(str[++i], args);
			len++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
