/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:43:54 by cwan              #+#    #+#             */
/*   Updated: 2023/09/11 14:32:06 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		cha;
	size_t				i;

	src = (const unsigned char *)s;
	cha = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == cha)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
