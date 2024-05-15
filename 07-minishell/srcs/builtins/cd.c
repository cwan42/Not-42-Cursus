/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:15:43 by cwan              #+#    #+#             */
/*   Updated: 2024/05/15 14:08:19 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replacenode(t_list **lst, char *cmd)
{
	(void)(cmd);
//	while (*lst)
//	{
//		if (!ft_strncmp((*lst)->content, "pwd=", 4))
		printf("%s\n", (char *)(*lst)->content);
//		lst++;
//	}
}

int	cd(t_tools *tools)
{
	chdir(tools->cmds[1]);
	replacenode(tools->env, tools->cmds[1]);
	return (0);
}
