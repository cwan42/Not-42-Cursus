/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:22:35 by cwan              #+#    #+#             */
/*   Updated: 2023/09/25 15:25:09 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h> // for variadic fns
# include <unistd.h> // for write
# include <stdlib.h> // for malloc
# include <string.h>
# include <stdio.h>

int		hexer(unsigned long n);
int		ft_printp(void *ptr);
int		ft_printu(unsigned int n);

int		ft_printf(const char *str, ...);

#endif
