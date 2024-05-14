/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/14 21:57:12 by cwan             ###   ########.fr       */
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
	printf("\033[32mminihell\033[0m$ ");
}

void	init_cmds(t_tools *tools, char *str)
{
	int	i;

	i = 0;
	if (tools->cmds && tools->tokens)
		freearr(tools->cmds);
//		ft_memset(tools->cmds, 0, tools->tokens);
	tools->cmds = ft_split(str, ' ');
	while (tools->cmds[i])
		i++;
	tools->tokens = i;
}

void	parser(t_tools *tools)
{
	if (!ft_strncmp(tools->cmds[0], "env", 3))
		print_env(tools);
	else if (!ft_strncmp(tools->cmds[0], "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(tools->cmds[0], "exit", 4))
		exithell(tools);
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
		parser(tools);
		free(line);
	}
	return (0);
}
