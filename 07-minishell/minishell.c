/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/09 18:00:17 by cwan             ###   ########.fr       */
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
/*
char	*readcmd(void)
{
	char	buffer[1024];
	char	*ptr = NULL;
	char	ptrlen = 0;

	while (fgets(buffer, 1024, stdin))
	{
		WIP
	}
}

void	print_prompt(void)
{
	ft_putstr_fd("prompt ", 2);
}

int	main(int ac, char **av, char **envp)
{
	t_tools	*tools;
	char	*cmd;

	tools = NULL;
	if (ac == 1 && !av[1])
	{
		ft_printf("Test minishell launched\n");
		tools = inittools(tools, envp);
	}
	while (1)
	{
		print_prompt();
		cmd = readcmd();
		if (!cmd)
			exit(1);
		if (!cmd[0] || !ft_strncmp(cmd, "\n", 1))
			free (cmd);
		if (!ft_strncmp(cmd, "exit\n", 5))
		{
			free (cmd);
			break ;
		}
		ft_printf("%s\n", cmd);
		free (cmd);
	}
//	minishellloop(tools);
//	for (int i = 0; tools->env[i]; i++)
//		ft_printf("%s\n", tools->env[i]);
	return (0);
}*/

//int	main(int ac, char **av, char **envp)
int	main()
{
	char	*line;

	while (1)
	{
		line = readline("Enter a command or type 'exit' to quit: ");
		if (line)
			break;
		if (!ft_strncmp(line, "exit", 4))
		{
			free(line);
			break;
		}
		ft_printf("You entered: %s\n", line);
		free(line);
	}
	return (0);
}
