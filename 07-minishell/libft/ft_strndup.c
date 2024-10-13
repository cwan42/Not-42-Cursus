/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:21:11 by cwan              #+#    #+#             */
/*   Updated: 2024/07/28 10:27:31 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dst;

	i = 0;
	while (i < n && src[i])
		i++;
	dst = (char *)ft_calloc(i + 1, sizeof(char));
	if (!dst)
		return (NULL);
	while (i > 0)
	{
		i--;
		dst[i] = src[i];
	}
	return (dst);
}
