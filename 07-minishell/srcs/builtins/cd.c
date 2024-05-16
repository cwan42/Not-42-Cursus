/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:15:43 by cwan              #+#    #+#             */
/*   Updated: 2024/05/16 14:49:55 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//single instance of invalid read on 2nd cd only, to investigate, for both fns
static void	choldpwd(t_list **lst)
{
	t_list	*tmp;
	char	*tmpstr;
	char	*cwd;

	tmp = *lst;
	tmpstr = NULL;
	while (tmp)
	{
		if (!ft_strncmp((char *)tmp->content, "OLDPWD=", 7))
		{
			cwd = ft_cwd();
			if (cwd)
			{
				tmpstr = ft_strjoin("OLDPWD=", cwd);
				free(cwd);
			}
			if (tmpstr)
			{
				tmp->content = tmpstr;
				free(tmpstr);
			}
			return ;
		}
		tmp = tmp->next;
	}
}

static void	chpwd(t_list **lst)
{
	t_list	*tmp;
	char	*tmpstr;
	char	*cwd;

	tmp = *lst;
	tmpstr = NULL;
	while (tmp)
	{
		if (!ft_strncmp((char *)tmp->content, "PWD=", 4))
		{
			cwd = ft_cwd();
			if (cwd)
			{
				tmpstr = ft_strjoin("PWD=", cwd);
				free(cwd);
			}
			if (tmpstr)
			{
				tmp->content = tmpstr;
				free(tmpstr);
			}
			return ;
		}
		tmp = tmp->next;
	}
}

int	cd(t_tools *tools)
{
	choldpwd(tools->env);
	chdir(tools->cmds[1]);
	chpwd(tools->env);
	return (0);
}
