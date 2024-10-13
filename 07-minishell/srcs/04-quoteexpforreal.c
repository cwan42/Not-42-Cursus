/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04-quoteexpforreal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:14:46 by cwan              #+#    #+#             */
/*   Updated: 2024/09/30 12:38:13 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*returnenvvalue(char *str, int *c, t_env **env)
{
	t_env	*tmp;
	char	*newstr;

	tmp = *env;
	newstr = NULL;
	while (tmp)
	{
		if (!ft_strncmp(&str[*c], tmp->name, ft_strlen(tmp->name)) && \
		!ft_isalnum(str[*c + ft_strlen(tmp->name)]))
		{
			newstr = ft_strdup(tmp->value);
			if (newstr)
				*c += ft_strlen(tmp->name);
			return (newstr);
		}
		tmp = tmp->n;
	}
	return (NULL);
}

char	*expandstr(t_tools *tools, char *str, int *c)
{
	char	*newstr;

	if (str[*c] == '$')
	{
		if (str[*c + 1] == '\0' || str[*c + 1] == ' ' || str[*c + 1] == '$')
		{
			(*c)++;
			return (ft_strdup("$"));
		}
		(*c)++;
		newstr = returnenvvalue(str, c, tools->env);
		if (newstr)
			return (newstr);
		if (str[*c] == '?')
			return ((*c)++, ft_itoa(tools->ecode));
		if (!newstr)
		{
			while (str[*c] && (ft_isalnum(str[*c]) || str[*c] == '_'))
				(*c)++;
			return (ft_strdup(""));
		}
	}
	return (NULL);
}

char	*copystr(char *str, int *c)
{
	char	*newstr;
	int		i;

	newstr = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	while (str[*c] && str[*c] != '$')
		newstr[i++] = str[(*c)++];
	return (newstr);
}

char	*quoteexpforreal(t_tools *tools, char *str)
{
	char	*newstr;
	char	*tmp;
	char	*tmpstr;
	int		i;

	newstr = ft_calloc(1, sizeof(char));
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			tmpstr = expandstr(tools, str, &i);
		else
			tmpstr = copystr(str, &i);
		if (!tmpstr)
			return (free(newstr), NULL);
		tmp = newstr;
		newstr = ft_strjoin(newstr, tmpstr);
		(void)(free(tmp), free(tmpstr));
	}
	return (newstr);
}
