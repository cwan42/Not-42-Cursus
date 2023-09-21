/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:22:35 by cwan              #+#    #+#             */
/*   Updated: 2023/09/21 11:07:14 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//int	ft_printf(const char *, ...);

void	ft_printc(char c);
void	ft_prints(char *s);
int		ft_printp(unsigned long ptr);
void	ft_printd(int n);

/*
malloc
free
write
va_start
va_arg
va_copy
va_end	

d - decimal (base 10)
i - integer (base 10)
u - unsigned dec (base 10)
x - number in lowercase (hex)
X - number in uppercase (hex)
% - percent sign
*/

#endif
