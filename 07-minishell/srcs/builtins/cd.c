/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:15:43 by cwan              #+#    #+#             */
/*   Updated: 2024/09/27 16:33:47 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	choldpwd(t_env **lst)
{
	t_env	*tmp;
	char	*cwd;

	tmp = *lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "OLDPWD"))
		{
			cwd = ft_cwd();
			if (cwd)
			{
				free(tmp->value);
				tmp->value = ft_strdup(cwd);
				free(cwd);
			}
		}
		tmp = tmp->n;
	}
}

static void	chpwd(t_env **lst)
{
	t_env	*tmp;
	char	*cwd;

	tmp = *lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PWD"))
		{
			cwd = ft_cwd();
			if (cwd)
			{
				free(tmp->value);
				tmp->value = ft_strdup(cwd);
				free(cwd);
			}
		}
		tmp = tmp->n;
	}
}

static void	cattilde(char *cmd, char *home)
{
	char	*path;
	int		i;
	int		j;

	i = 1;
	j = -1;
	path = ft_calloc(ft_strlen(home) + ft_strlen(cmd), sizeof(char *));
	while (home[++j])
		path[j] = home[j];
	while (cmd[i])
		path[j++] = cmd[i++];
	chdir(path);
	free(path);
}

int	cdactual(char **cmds, t_env **env, char *home)
{
	if ((cmdscount(cmds) == 1 || !ft_strcmp(cmds[1], "~")) && !home)
		return (printf("cd: HOME not set\n"), -2);
	choldpwd(env);
	if (cmdscount(cmds) == 1)
		chdir(home);
	else if (cmds[1][0] == '~')
		cattilde(cmds[1], home);
	else if (access(cmds[1], F_OK) == -1)
		return (-1);
	else
		chdir(cmds[1]);
	chpwd(env);
	return (0);
}

int	cd(t_tools *tools)
{
	char	**cmds;
	char	*home;
	t_env	*tmp;

	tmp = *tools->env;
	home = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "HOME"))
			home = tmp->value;
		tmp = tmp->n;
	}
	cmds = (*tools->cmdtab)->cmds;
	if (cmdscount(cmds) > 2)
		return (ft_putstr_fd("cd: too many arguments\n", 2), 1);
	else
	{
		if (cdactual(cmds, tools->env, home) == -1)
			return (errmsg("cd", cmds[1], 1), 1);
	}
	return (0);
}
