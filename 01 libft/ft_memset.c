/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:59:20 by cwan              #+#    #+#             */
/*   Updated: 2023/09/07 09:09:17 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char	*bc;
	unsigned char	cc;

	i = 0;
	bc = (unsigned char *)b;
	cc = (unsigned char)c;
	while (i < len)
		bc[i++] = cc;
	return (b);
}
