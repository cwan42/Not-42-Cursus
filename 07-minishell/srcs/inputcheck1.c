/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheck1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:06:11 by cwan              #+#    #+#             */
/*   Updated: 2024/10/12 15:57:12 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	firstcharpipe(const char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '|')
		return (1);
	return (0);
}

int	dblpipecheck(const char *line)
{
	const char	*start = line;

	if (firstcharpipe(line))
		return (errmsg(NULL, NULL, 8), 1);
	while (*line)
	{
		if (*line == '|' && !checkquotes(start, line))
		{
			line++;
			while (*line == ' ')
				line++;
			if (*line == '|')
				return (errmsg(NULL, NULL, 8), 1);
		}
		line++;
	}
	return (0);
}

int	lastpipespacecheck(const char *line)
{
	const char	*start = line;
	int			flag;

	flag = 0;
	while (*line)
	{
		if (checkquotes(start, line))
		{
			line++;
			continue ;
		}
		if (*line == '|')
			flag = 1;
		else if (*line != ' ' && *line != '\t')
			flag = 0;
		line++;
	}
	if (flag)
		return (errmsg(NULL, NULL, 8), flag);
	return (0);
}

int	errorcheck(t_tools *tools, char *cline)
{
	if (!lastpipespacecheck(cline) && !dblpipecheck(cline) && \
		checkopenquote(tools, cline) && !checkthreesome(cline) && \
		!checkdouble_redirect(cline) && !setcmds(tools, cline))
		return (0);
	else
		return (1);
}
