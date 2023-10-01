/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:42:57 by cwan              #+#    #+#             */
/*   Updated: 2023/10/01 14:27:37 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str++ && (*str != (char)c))
		str++;
	if ((*str) == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strducpy(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (str[i] && (i < ft_strlen(s)))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !result)
		return (NULL);
	while (s1[i++])
		result[i] = s1[i];
	while (s2[j++])
		result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}
