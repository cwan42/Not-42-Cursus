/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/10 12:42:16 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void init_hist(t_tools *tools)
{
	char	*history[499];
	int		hist_head;
	int		hist_size;

	hist_head = 0;
	hist_size = 0;
}*/

t_tools	*inittools(t_tools *tools, char **envp)
{
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	tools->simplecmds = 0;
	init_env(tools, envp);
//	init_hist(tools);
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
			print_env(tools);
		else if (!ft_strncmp(line, "pwd", 3))
			ft_pwd();
		else if (!ft_strncmp(line, "exit", 4))
			exit(1);
		else if (line)
			ft_printf("%s%s\n", line, " : command not found");
		free(line);
	}
	return (0);
}
