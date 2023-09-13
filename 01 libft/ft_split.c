/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:22:39 by cwan              #+#    #+#             */
/*   Updated: 2023/09/13 13:56:22 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_arrsize(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (*s != c)
		{
			size++;
			s++;
		}
		else
			s++;
	}
	return (size);
}

static char	**ft_splitfree(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**splitarr;
	size_t	i;
	size_t	len;

	if (!s || !c)
		return (NULL);
	splitarr = malloc(sizeof(char *) * ft_arrsize(s, c) + 1);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			splitarr[i] = ft_substr(s - len, 0, len);
			if (!splitarr[i++])
				return (ft_splitfree(splitarr));
		}
		else
			s++;
	}
	splitarr[i] = 0;
	return (splitarr);
}
