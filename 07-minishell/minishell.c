/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/16 16:55:27 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tools	*inittools(t_tools *tools, char **envp)
{
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	init_env(tools, envp);
	return (tools);
}

/*
void	identtype(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->content[0] ==
		else if (tmp->content[0] ==
		else

	}
}*/

void	setcmds(t_tools *tools, char *str)
{
	int	i;

	i = 0;
	if (tools->cmds && tools->tokens)
	{
		freearr(tools->cmds);
		tools->tokens = 0;
	}
	tools->cmds = ft_split(str, ' ');
//	identtype(tools->cmds);
	while (tools->cmds[i])
		i++;
	tools->tokens = i;
}

void	parser(t_tools *tools)
{
	if (!ft_strncmp(tools->cmds[0], "env", 3))
		print_env(tools);
	else if (!ft_strncmp(tools->cmds[0], "cd", 2))
		cd(tools);
	else if (!ft_strncmp(tools->cmds[0], "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(tools->cmds[0], "exit", 4))
		exithell(tools);
	else if (!ft_strncmp(tools->cmds[0], "ls", 2))
		execve("/bin/ls", &tools->cmds[0], NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_tools	*tools;
	char	*line;

	tools = NULL;
	(void)(ac);
	(void)(av[0]);
	ft_printf("Minihell loaded, enter command or type 'exit' to quit.\n");
	tools = inittools(tools, envp);
	while (1)
	{
		line = readline("\033[32mminihell\033[0m$ ");
		if (!line)
			break ;
		add_history(line);
		setcmds(tools, line);
		parser(tools);
		free(line);
	}
	return (0);
}
