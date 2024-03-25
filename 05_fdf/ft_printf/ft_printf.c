/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:07:45 by cwan              #+#    #+#             */
/*   Updated: 2023/09/26 16:41:50 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c || !c)
		return ((char *)s);
	return (NULL);
}

int	ft_hexconv(unsigned long n, char *base)
{
	int	i;

	i = 0;
	if (n > 15)
		i += ft_hexconv((n / 16), base);
	i += ft_putchar(base[n % 16]);
	return (i);
}

static int	ft_formatspec(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i += ft_printp(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putunsnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_hexconv(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		i += ft_hexconv(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
			len += ft_formatspec(str[++i], args);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
