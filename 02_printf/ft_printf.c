/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:53:15 by cwan              #+#    #+#             */
/*   Updated: 2023/09/22 16:24:06 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_formatspec(const char c, va_list args)
{
	if (c == 'c')
		ft_printc(va_arg(args, int));
	else if (c == 's')
		ft_prints(va_arg(args, char *));
	else if (c == 'p')
		ft_printp(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		ft_printd(va_arg(args, int));
	else
		ft_printc('%');
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
	
	i = 0;
	va_start	(args, str);
	while (str[i])
	{
		if (str[i] == '%' && validformat(str[i + 1]))
			ft_formatspec(str[++i], args);
		else
			ft_printc(str[i]);
		i++;
	}
	va_end(args);
	return (0);
}
