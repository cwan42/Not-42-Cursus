/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:11:47 by cwan              #+#    #+#             */
/*   Updated: 2023/11/07 15:21:02 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t numelem, size_t size)
{
	void			*array;
	size_t			i;
	unsigned char	*ptr;

	array = malloc(numelem * size);
	if (!array)
		return (NULL);
	i = 0;
	ptr = array;
	while (i < (numelem * size))
		ptr[i++] = '\0';
	return (array);
}
