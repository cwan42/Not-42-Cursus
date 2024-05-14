/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/14 17:07:33 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tools	*inittools(t_tools *tools, char **envp)
{
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	init_env(tools, envp);
	return (tools);
}

void	init_prompt(void)
{
	ft_putstr("\033[32mminihell\033[0m$ ");
}

void	init_cmds(t_tools *tools, char *str)
{
	int	i;

	i = 0;
	tools->cmds = ft_split(str, ' ');
	while (str[i])
		i++;
	tools->tokens = i;
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
		if (!line)
			break ;
		add_history(line);
		init_cmds(tools, line);
		if (!ft_strncmp(line, "env", 3))
			print_env(tools);
		else if (!ft_strncmp(line, "pwd", 3))
			ft_pwd();
		else if (!ft_strncmp(line, "exit", 4))
			exithell(tools);
		free(line);
	}
	return (0);
}
