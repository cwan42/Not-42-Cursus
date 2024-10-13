/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:27:59 by cwan              #+#    #+#             */
/*   Updated: 2024/09/27 16:56:48 by cbandara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
}

int	cmdscount(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

// MISC to be deleted

void	printarray(char **arr)
{
	int	i;

	i = 0;
	printf("Array is ");
	while (arr[i])
		printf("%s, ", arr[i++]);
	printf("\n");
}

void	print2(t_cmd *tab)
{
	t_cmd	*tmp;

	tmp = tab;
	while (tmp)
	{
		printarray(tmp->rd);
		printarray(tmp->cmds);
		tmp = tmp->n;
	}
}

int	handle_null_cmds(t_tools *tools, t_cmd *cmd)
{
	int		i;
	int		j;
	int		k;
	char	**newcmds;

	i = 0;
	j = 0;
	k = 0;
	while (cmd->cmds[i] && !cmd->cmds[i][0])
		i++;
	if (!cmd->cmds[i] || !i)
		return (0);
	j = i;
	while (cmd->cmds[j])
		j++;
	newcmds = ft_calloc(j - i + 1, sizeof(char *));
	if (!newcmds)
		return (0);
	while (cmd->cmds[i])
		newcmds[k++] = ft_strdup(cmd->cmds[i++]);
	freearr((*tools->cmdtab)->cmds);
	(*tools->cmdtab)->cmds = newcmds;
	return (0);
}
