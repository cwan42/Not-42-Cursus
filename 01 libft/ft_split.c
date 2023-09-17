/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:22:39 by cwan              #+#    #+#             */
/*   Updated: 2023/09/17 11:50:24 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (i);
}

static void	*ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arrarr;
	size_t	i;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_wordcount(s, c);
	arrarr = malloc(sizeof(char *) * (wordcount + 1));
	if (!arrarr)
		return (NULL);
	arrarr[wordcount] = NULL;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			arrarr[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!arrarr[i++])
				return (ft_free(arrarr));
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (arrarr);
}
