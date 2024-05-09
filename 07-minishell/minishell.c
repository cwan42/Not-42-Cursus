/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/09 23:07:43 by cwan42           ###   ########.fr       */
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

void	init_prompt(void)
{
	ft_putstr("\033[32mminihell\033[0m$ ");
}

int	main(int ac, char **av, char **envp)
{
	t_tools	*tools;
	char	*line;

	tools = NULL;
	if (ac == 1 && !av[1])
	{
		ft_printf("Minihell loaded, enter command or type 'exit' to quit.\n");
		tools = inittools(tools, envp);
	}
	while (1)
	{
		init_prompt();
		line = readline(NULL);
		if (!ft_strncmp(line, "env", 3))
			for (int i = 0; tools->env[i]; i++)
				ft_printf("%s\n", tools->env[i]);
		if (!ft_strncmp(line, "exit", 4))
			exit(1);
	}
	return (0);
}
