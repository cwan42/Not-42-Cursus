/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:48 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/26 14:03:20 by cbandara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**newenvp(t_tools *tools)
{
	char	**newenvp;
	int		i;
	t_env	*tmp;
	char	*nameequals;

	i = 0;
	tmp = *tools->env;
	while (tmp)
	{
		i++;
		tmp = tmp->n;
	}
	newenvp = ft_calloc(i + 1, sizeof(char *));
	tmp = *tools->env;
	i = 0;
	while (tmp)
	{
		nameequals = ft_strjoin(tmp->name, "=");
		newenvp[i++] = ft_strjoin(nameequals, tmp->value);
		free(nameequals);
		tmp = tmp->n;
	}
	i = 0;
	return (newenvp);
}

void	initsmolenv(t_tools *tools)
{
	t_env	*node;
	t_env	*node2;
	char	cwd[4096];
	char	*path;
	char	*path2;

	node = (t_env *)ft_calloc(1, sizeof(t_env));
	node->name = ft_strdup("PWD");
	node->value = ft_strdup(getcwd(cwd, 4096));
	*tools->env = node;
	node2 = (t_env *)ft_calloc(1, sizeof(t_env));
	node2->name = ft_strdup("PATH");
	path = ("/home/cwan/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:");
	path2 = ("/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:");
	node2->value = ft_strjoin(path, path2);
	node->n = node2;
	node2->n = NULL;
}

void	initrealenv(t_tools *tools, char **envp)
{
	int		j;
	t_env	*tmp;
	t_env	*node;

	tmp = NULL;
	while (*envp)
	{
		j = 0;
		while ((*envp)[j] != '=')
			j++;
		node = (t_env *)ft_calloc(1, sizeof(t_env));
		node->name = (char *)ft_calloc(j + 1, sizeof(char));
		while (j--)
			node->name[j] = (*envp)[j];
		node->value = ft_strdup(ft_strchr((*envp), '=') + 1);
		envp++;
		if (tmp)
			tmp->n = node;
		else
			*tools->env = node;
		tmp = node;
	}
}

void	init_env(t_tools *tools, char **envp)
{
	tools->envp = envp;
	tools->env = (t_env **)ft_calloc(1, sizeof(t_env *));
	if (!*envp)
	{
		initsmolenv(tools);
	}
	else if (envp)
		initrealenv(tools, envp);
}

void	print_env(t_tools *tools, t_cmd *tab)
{
	t_env	*node;

	if (tab->cmds[1])
	{
		tools->ecode = 127;
		errmsg("env", (*tools->cmdtab)->cmds[1], 1);
		return ;
	}
	node = *tools->env;
	while (node)
	{
		if (node->name && node->value)
			printf("%s=%s\n", node->name, node->value);
		node = node->n;
	}
	tools->ecode = 0;
}
