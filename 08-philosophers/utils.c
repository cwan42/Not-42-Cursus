/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:33:22 by cwan              #+#    #+#             */
/*   Updated: 2024/10/13 09:33:27 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		result = (result * 10) + (str[i++] - '0');
	if (result < 0)
		return (0);
	if (result > 2147483646)
		return (2147483647);
	return (sign * result);
}

void	*ft_calloc(size_t numelem, size_t size)
{
	void			*array;
	size_t			i;

	array = malloc(numelem * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < (numelem * size))
		((char *)array)[i++] = '\0';
	return (array);
}
