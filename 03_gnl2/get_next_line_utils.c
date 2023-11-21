/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:11:47 by cwan              #+#    #+#             */
/*   Updated: 2023/11/21 13:13:49 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*str;
	char	*ptr;

	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	return (result);
}
/*
void	ft_strlcpy(char *s1, char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (*s2 && i < size - 1)
		*s1++ = *s2++;
	*s1 = '\0';
}
*/

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
