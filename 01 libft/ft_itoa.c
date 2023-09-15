/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:02:45 by cwan              #+#    #+#             */
/*   Updated: 2023/09/15 12:26:33 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;

	i = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i--] = '0' + (n % 10);
		n /= 10;
	}
	if (sign == 1)
		str[i] = '-';
	return (str);
}
