/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiedsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:43:59 by cwan              #+#    #+#             */
/*   Updated: 2024/07/28 11:07:20 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	inquotes(char const *str, char *c)
{
	int	dubq;
	int	sinq;

	dubq = 0;
	sinq = 0;
	while (*str)
	{
		if (str == c && !(dubq % 2) && !(sinq % 2))
			return (0);
		if (*str == '\"' && !(sinq % 2))
			dubq++;
		if (*str == '\'' && !(dubq % 2))
			sinq++;
		if (str == c && !(dubq % 2) && !(sinq % 2))
			return (0);
		str++;
	}
	return (1);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;
	int	inq;

	len = 0;
	inq = 0;
	while (*s && (*s != c || inq))
	{
		if (*s == '"' || *s == '\'')
		{
			if (!inq)
				inq = *s;
			else if (*s == inq)
				inq = 0;
		}
		s++;
		len++;
	}
	return (len);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			i++;
			s += ft_wordlen(s, c);
		}
	}
	return (i);
}

int	allocater(char **arr, size_t len, const char *s, char c)
{
	if (inquotes(s, &c))
	{
		*arr = (char *)ft_calloc(len + 1, sizeof(char));
		if (!*arr)
			return (1);
		ft_strncpy(*arr, s, len);
	}
	else
	{
		*arr = ft_strndup(s, len);
		if (!*arr)
			return (1);
	}
	return (0);
}

char	**ft_modsplit(const char *s, char c)
{
	size_t	i;
	char	**arrarr;
	size_t	len;

	arrarr = (char **)ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!s || !arrarr)
		return (freearr(arrarr), NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			len = ft_wordlen(s, c);
			if (allocater(&arrarr[i], len, s, c) == 1)
				return (freearr(arrarr), NULL);
			i++;
			s += len;
		}
	}
	return (arrarr);
}
/*			if (inquotes(s, &c))
			{
				arrarr[i] = ft_calloc(len + 1, sizeof(char));
				if (!arrarr[i])
					return (freearr(arrarr), NULL);
				ft_strncpy(arrarr[i], s, len);
			}
			else
			{
				arrarr[i] = ft_strndup(s, len);
				if (!arrarr[i])
					return (freearr(arrarr), NULL);
			}*/
