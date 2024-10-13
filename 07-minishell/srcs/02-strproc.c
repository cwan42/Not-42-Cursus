/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-strproc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:32:20 by cwan              #+#    #+#             */
/*   Updated: 2024/09/24 01:24:46 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checkquotes(char const *str, const char *c)
{
	int	sinq;
	int	dubq;

	sinq = 0;
	dubq = 0;
	while (*str && str < c)
	{
		if (*str == '\'' && !dubq)
			sinq = !sinq;
		else if (*str == '"' && !sinq)
			dubq = !dubq;
		str++;
	}
	return (sinq || dubq);
}

static int	initcmdtabstrs(char **rd, char **cmd, t_cmd *tab)
{
	tab->redir = (char *)malloc(sizeof(char) * 300);
	tab->cmd = (char *)malloc(sizeof(char) * 300);
	if (!tab->redir || !tab->cmd)
		return (-1);
	*rd = tab->redir;
	*cmd = tab->cmd;
	return (0);
}

static void	uglyending(char **rd, char **cmd, t_cmd *tab)
{
	**rd = '\0';
	**cmd = '\0';
	tab->rd = ft_modsplit(tab->redir, ' ');
	tab->cmds = ft_modsplit(tab->cmd, ' ');
}

int	strproc(t_cmd *tab, char *str)
{
	char	*rd;
	char	*cmd;
	char	*origstr;

	if (initcmdtabstrs(&rd, &cmd, tab) == -1)
		return (freecmdtab(&tab), -1);
	origstr = str;
	while (*str)
	{
		if ((*str != '<' && *str != '>') || checkquotes(origstr, str))
			*cmd++ = *str++;
		else if (*str == '<')
		{
			if (copychars(&rd, &str, '<') == -1)
				return (-1);
		}
		else if (*str == '>')
		{
			if (copychars(&rd, &str, '>') == -1)
				return (-1);
		}
	}
	uglyending(&rd, &cmd, tab);
	return (0);
}
