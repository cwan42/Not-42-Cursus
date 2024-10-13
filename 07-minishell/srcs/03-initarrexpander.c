/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03-initarrexpander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:12:09 by cwan              #+#    #+#             */
/*   Updated: 2024/10/12 15:22:22 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*endquoteexp(t_tools *tools, char *newstr, int type)
{
	char	*tmpstr;

	if (type == 1 || type == 0)
	{
		tmpstr = quoteexpforreal(tools, newstr);
		return (free(newstr), tmpstr);
	}
	return (newstr);
}

static char	*quoteexp(t_tools *tools, char *str, int *c, int type)
{
	int		tmp;
	int		i;
	char	*newstr;

	tmp = *c;
	i = 0;
	if (type == 1 || type == 2)
	{
		tmp = *c + 1;
		(*c)++;
		while ((type == 1 && str[*c] && str[*c] != '"') || \
		(type == 2 && str[*c] && str[*c] != '\''))
			(*c)++;
	}
	while (!type && str[*c] && str[*c] != '"' && str[*c] != '\'')
		(*c)++;
	newstr = (char *)ft_calloc((*c) - tmp + 1, sizeof(char));
	while (tmp < *c)
		newstr[i++] = str[tmp++];
	if ((type == 1 || type == 2) && str[*c])
		(*c)++;
	return (endquoteexp(tools, newstr, type));
}

/*
char *reproc(char **cmds, char *str)
{
	int i = 0;
	int j = 0;
	char *last;

	printf("%s\n", str);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		j = i;
    	while (str[i] && str[i] != ' ')
    		i++;
    	if (i > j)
    	{
    		*cmds = ft_strndup(str + j, i - j);
	   		cmds++;
	   	}
	}
	if (i > j)
		last = ft_strndup(str + j, i - j);
	else
		last = NULL;
	free(str);
	return (last);
}*/

static void	arrexpander(t_tools *tools, char **cmds)
{
	char	*sub;
	char	*tmp;
	char	*tmpstr;
	int		i;

	while (*cmds)
	{
		i = 0;
		sub = ft_calloc(1, sizeof(char));
		while ((*cmds)[i])
		{
			tmp = sub;
			if ((*cmds)[i] != '"' && (*cmds)[i] != '\'')
				tmpstr = quoteexp(tools, *cmds, &i, 0);
			else if ((*cmds)[i] == '"')
				tmpstr = quoteexp(tools, *cmds, &i, 1);
			else if ((*cmds)[i] == '\'')
				tmpstr = quoteexp(tools, *cmds, &i, 2);
			sub = ft_strjoin(sub, tmpstr);
			free(tmp);
			free(tmpstr);
		}
		(void)(free(*cmds), *cmds = sub, cmds++);
	}
}

void	arrdexpander(char **cmds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmds[i])
	{
		if (cmds[i][0])
		{
			cmds[j] = cmds[i];
			j++;
		}
		else
			free(cmds[i]);
		i++;
	}
	cmds[j] = NULL;
}

void	initarrexpander(t_tools *tools)
{
	t_cmd	*tmp;

	tmp = *tools->cmdtab;
	while (tmp)
	{
		arrexpander(tools, tmp->rd);
		arrexpander(tools, tmp->cmds);
		arrdexpander(tmp->cmds);
		tmp = tmp->n;
	}
}
