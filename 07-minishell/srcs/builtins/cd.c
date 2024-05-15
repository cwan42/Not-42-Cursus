/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:15:43 by cwan              #+#    #+#             */
/*   Updated: 2024/05/15 16:15:37 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	replacenode(t_list **lst)
{
	t_list	*tmp;
	char	*tmpstr;

	tmp = *lst;
	while (tmp)
	{
		if (!ft_strncmp((char *)tmp->content, "PWD=", 4))
			printf("%s\n", (char *)tmp->content);
		if (!ft_strncmp((char *)tmp->content, "OLDPWD=", 7))
		{
			tmpstr = ft_strjoin("OLDPWD=", ft_pwd());
			printf("%s\n", tmpstr);
		}
		tmp = tmp->next;		
	}
}*/

int	cd(t_tools *tools)
{
//	replacenode(tools->env);
	chdir(tools->cmds[1]);
	return (0);
}
