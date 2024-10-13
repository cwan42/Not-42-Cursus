/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:00:36 by cwan              #+#    #+#             */
/*   Updated: 2024/09/26 13:57:21 by cbandara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_modenv(t_env *env)
{
	t_env	*node;

	node = env;
	while (node)
	{
		if (node->value)
			printf("declare -x %s=%s\n", node->name, node->value);
		else
			printf("declare -x %s\n", node->name);
		node = node->n;
	}
}

static t_env	*createnode(char *words)
{
	int		i;
	t_env	*toadd;

	i = 0;
	toadd = ft_calloc(1, sizeof(t_env));
	while (words[i] != '=' && words[i])
		i++;
	toadd->name = ft_calloc(i + 1, sizeof(char));
	while (i--)
		toadd->name[i] = words[i];
	return (toadd);
}

static void	addnodeenv(t_tools *tools, char *words)
{
	t_env	*node;
	t_env	*toadd;

	toadd = createnode(words);
	node = *tools->env;
	while (node)
	{
		if (ft_strcmp(node->name, toadd->name) == 0)
		{
			free(node->value);
			node->value = ft_strdup(ft_strchr(words, '=') + 1);
			free(toadd->name);
			free(toadd);
			return ;
		}
		node = node->n;
	}
	node = *tools->env;
	while (node->n)
		node = node->n;
	toadd->value = ft_strdup(ft_strchr(words, '=') + 1);
	toadd->n = NULL;
	node->n = toadd;
}
/*
static void	addnodeexport(t_tools *tools, char *words)
{
	t_env	*node;
	t_env	*toadd;

	node = *tools->env;
	while (node->n)
		node = node->n;
	toadd = ft_calloc(1, sizeof(t_env));
	toadd->name = ft_strdup(words);
	toadd->value = NULL;
	toadd->n = NULL;
	node->n = toadd;
}*/

int	validname(char *exp)
{
	int	i;

	i = 0;
	while (exp[i] && exp[i] != '=')
	{
		if (exp[i] == '-' || exp[i] == '+' || exp[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_export(t_tools *tools)
{
	char	**exp;

	exp = (*tools->cmdtab)->cmds;
	if (cmdscount((*tools->cmdtab)->cmds) == 1)
		print_modenv(*tools->env);
	else if (cmdscount((*tools->cmdtab)->cmds) > 1)
	{
		exp++;
		while (*exp)
		{
			if ((*exp)[0] == '=' || validname(*exp) || ft_isdigit((*exp)[0]))
			{
				errmsg("export", *exp, 99);
				tools->ecode = 1;
				break ;
			}
			else if (ft_strchr(*exp, '='))
				addnodeenv(tools, *exp);
			exp++;
		}
	}
	return (tools->ecode);
}
