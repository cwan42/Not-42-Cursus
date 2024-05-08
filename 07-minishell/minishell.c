/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/08 21:26:39 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_tools
{
	char	*argline;
	char	**env;
	int		simplecmds;
}			t_tools;

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	initenvp(t_tools *tools, char **envp)
{
	int		i;

	i = 0;	
	while (envp[i])
		i++;
	tools->env = ft_calloc(sizeof(char *), i + 1);
	if (!tools->env)
		return ;
	i = -1;
	while (envp[++i])
	{
		tools->env[i] = ft_strdup(envp[i]);
		if (!tools->env[i])
			ft_free(tools->env);
	}
}

t_tools	*inittools(t_tools *tools, char **envp)
{
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	tools->simplecmds = 0;
	initenvp(tools, envp);
	return (tools);
}

int	minishellloop(t_tools *tools)
{
//	tools->argline = readline("Test minishell launched\n");
	(void)(tools);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_tools	*tools;

	tools = NULL;
	if (ac == 1 && !av[1])
	{
		ft_printf("Test minishell launched\n");
		tools = inittools(tools, envp);
	}
	minishellloop(tools);
	for (int i = 0; tools->env[i]; i++)
		ft_printf("%s\n", tools->env[i]);
	return (0);
}
