/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/10 00:03:50 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_tools
{
	char	*argline;
	t_list	**env;
	int		simplecmds;
}			t_tools;

void	init_env(t_tools *tools, char **envp)
{
	int		i;
	t_list	*node;

	i = 0;
	tools->env = malloc(sizeof(t_list *));
	*tools->env = NULL;
	while (envp[i])
	{
		node = ft_lstnew(envp[i]);
		if (!node)
			return ;
		ft_lstadd_back(tools->env, node);
		i++;
	}
}

t_tools	*inittools(t_tools *tools, char **envp)
{
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	tools->simplecmds = 0;
	init_env(tools, envp);
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
			for (t_list *node = *tools->env; node; node = node->next)
				ft_printf("%s\n", (char *)node->content);
		if (!ft_strncmp(line, "exit", 4))
			exit(1);
	}
	return (0);
}
