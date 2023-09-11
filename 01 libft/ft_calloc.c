/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:34:37 by cwan              #+#    #+#             */
/*   Updated: 2023/09/11 15:03:42 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	totalsize;
	void	*arr;

	totalsize = nmemb * size;
	arr = malloc(totalsize);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, totalsize);
	return (arr);
}
