/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:39:28 by cwan              #+#    #+#             */
/*   Updated: 2023/09/11 10:23:42 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != 0)
	{
		if (*s == (char)c)
		{
			last = s;
		}
		s++;
	}
	if (last != NULL)
		return ((char *)last);
	else if (c == '\0')
		return ((char *)s);
	else
		return (NULL);
}