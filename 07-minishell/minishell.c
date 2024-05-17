/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/17 16:03:46 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tools	*inittools(t_tools *tools, char **envp)
{
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	init_env(tools, envp);
	return (tools);
}

int	inittype(t_tools *tools)
{
	int		i;

	i = 0;
	if (tools->type)
	{
		free(tools->type);
		tools->type = NULL;
	}
	tools->type = malloc(tools->tokens * sizeof(int));
	ft_memset(tools->type, 2, tools->tokens * sizeof(int));
	while (tools->cmds[i])
	{
		if (i == 0 || !ft_strncmp(tools->cmds[i - 1], "|", 1))
			tools->type[i] = 3;
		else if (!ft_strncmp(tools->cmds[i], "<<", 2))
			tools->type[i] = 2;
		else if (!ft_strncmp(tools->cmds[i], "<", 1))
			tools->type[i] = 1;
		else if (!ft_strncmp(tools->cmds[i], "\"", 1))
			tools->type[i] = 5;
		else if (!ft_strncmp(tools->cmds[i], "\'", 1))
			tools->type[i] = 6;
		else if (!ft_strncmp(tools->cmds[i], "|", 1))
			tools->type[i] = 7;
		else if (!ft_strncmp(tools->cmds[i], ">>", 2))
			tools->type[i] = 9;
		else if (!ft_strncmp(tools->cmds[i], ">", 1))
			tools->type[i] = 8;
		else
			tools->type[i] = 4;
		i++;
	}
	tools->type[i] = '\0';
	i = 0;
	while (tools->type[i])
		printf("%d ", tools->type[i++]);
	printf("\n");
	return (0);
}
/*
char	*addspacestostr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>' || str[i] == '|'
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
//preprocess str here by adding spaces where there should be spaces but aren't
	tools->cmds = ft_split(str, ' ');
	while (tools->cmds[i])
		i++;
	tools->tokens = i;
	inittype(tools);
}

void	trueparser(t_tools *tools)
{
	
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
