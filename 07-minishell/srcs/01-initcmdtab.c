/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-initcmdtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:10:01 by cwan              #+#    #+#             */
/*   Updated: 2024/09/06 19:58:45 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_cmdtabaddback(t_cmd **tab, t_cmd *new)
{
	t_cmd	*tmp;

	if (!*tab)
		*tab = new;
	else
	{
		tmp = *tab;
		while (tmp->n)
			tmp = tmp->n;
		tmp->n = new;
	}
}

static t_cmd	*ft_cmdtabnew(char *arr)
{
	t_cmd	*node;

	node = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!node)
		return (NULL);
	if (strproc(node, arr) == -1)
		return (free(node), NULL);
	return (node);
}

int	setcmds(t_tools *tools, char *str)
{
	int		i;
	char	**splitcmds;
	char	**arr;

	i = 0;
	splitcmds = ft_modsplit(str, '|');
	if (!splitcmds || !*splitcmds)
		return (freearr(splitcmds), -1);
	arr = splitcmds;
	tools->cmdtab = (t_cmd **)malloc(sizeof(t_cmd *));
	if (!tools->cmdtab)
		return (freearr(splitcmds), -1);
	*tools->cmdtab = NULL;
	while (arr[i])
		ft_cmdtabaddback(tools->cmdtab, ft_cmdtabnew(arr[i++]));
	if (arr && *arr)
		initarrexpander(tools);
	return (freearr(splitcmds), 0);
}
