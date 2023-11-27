/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:02:45 by cwan              #+#    #+#             */
/*   Updated: 2023/09/17 09:23:36 by cwan             ###   ########.fr       */
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
	int		n2;
	int		i;

	i = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n2 = n;
	if (n < 0)
		n2 = -n;
	str = malloc(sizeof(char) * (i +1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n2 == 0)
		str[i] = '0';
	while (n2 > 0)
	{
		str[i--] = (n2 % 10) + '0';
		n2 /= 10;
	}
	if (n < 0)
		str[i] = '-';
	return (str);
}
