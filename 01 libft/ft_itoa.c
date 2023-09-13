/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:02:45 by cwan              #+#    #+#             */
/*   Updated: 2023/09/13 15:06:01 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int				i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		i = 2;
		num = -n;
	}
	while (num > 9)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static void	ft_invert(char *str, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;

	str = malloc(ft_intlen(n) + 1);
	i = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n)
	{
		str[i++] = '0' + n % 10;
		n /= 10;
	}
	if (i == 0)
		str[i++] = '0';
	if (sign)
		str[i++] = '-';
	str[i] = '\0';
	ft_invert(str, i);
	return (ft_strdup(str));
}
