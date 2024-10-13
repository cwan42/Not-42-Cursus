/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:36:03 by cbandara          #+#    #+#             */
/*   Updated: 2024/10/12 15:26:19 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig = 0;

int	checkopenquote(t_tools *tools, const char *line)
{
	char	quote;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			quote = line[i];
			i++;
			while (line[i] && line[i] != quote)
				i++;
			if (!line[i])
			{
				tools->ecode = 2;
				ft_putstr_fd("syntax error: open quote\n", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

//function to replace tabs with spaces
void	re_tabstospaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}

//function to sanitize the input by removing non-printable characters
char	*sanitize_input(const char *line)
{
	char	*cleaned_line;
	int		i;
	int		j;

	cleaned_line = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	if (!cleaned_line)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]) || line[i] == '\t' || line[i] == ' ')
			cleaned_line[j++] = line[i];
		i++;
	}
	re_tabstospaces(cleaned_line);
	return (cleaned_line);
}

static int	main_loop(t_tools *tools, const char *prompt)
{
	char	*line;
	char	*cline;

	while (1)
	{
		init_sig(tools);
		line = readline(prompt);
		if (g_sig == 130)
		{
			tools->ecode = g_sig;
			g_sig = 0;
		}
		if (!line)
			break ;
		if (*line)
			add_history(line);
		cline = sanitize_input(line);
		if (!errorcheck(tools, cline))
			(void)(free(cline), initexecute(tools), freecmdtab(tools->cmdtab));
		else
			free(cline);
		free(line);
	}
	return (freeheredocs(tools), freeenv(tools->env), free(tools), 0);
}

int	main(int ac, char **av, char **envp)
{
	t_tools	*tools;
	char	*prompt;

	if (ac != 1 || av[1])
		(void)(av);
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	init_env(tools, envp);
	prompt = "\001\033\[95m\002minihell\001\033[0m\002$ ";
	return (main_loop(tools, prompt));
}

/*
//the code didn't handle ctrl v and tab

int	checkopenquote(t_tools *tools, const char *line)
{
	char	quote;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			quote = line[i];
			i++;
			while (line[i] && line[i] != quote)
				i++;
			if (!line[i])
			{
				tools->ecode = 2;
				ft_putstr_fd("syntax error: open quote\n", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

static int	main_loop(t_tools *tools, const char *prompt)
{
	char	*line;

	while (1)
	{
		init_sig(tools);
		line = readline(prompt);
		if (g_sig == 130)
		{
			tools->ecode = g_sig;
			g_sig = 0;
		}
		if (!line)
			break ;
		if (*line)
			add_history(line);
		if (checkopenquote(tools, line) && !checkthreesome(line) && \
		!checkdouble_redirect(line) && !setcmds(tools, line))
			(void)(initexecute(tools), freecmdtab(tools->cmdtab));
		free(line);
	}
	return (freeenv(tools->env), free(tools), 0);
}

int	main(int ac, char **av, char **envp)
{
	t_tools	*tools;
	char	*prompt;

	if (ac != 1 || av[1])
		(void)(av);
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	init_env(tools, envp);
	prompt = "\001\033\[95m\002minihell\001\033[0m\002$ ";
	return (main_loop(tools, prompt));
}
*/
/*
int	main(int ac, char **av, char **envp)
{
	t_tools	*tools;
	char	*line;
	char	*prompt;

	if (ac != 1 || av[1])
		(void)(av);
	tools = (t_tools *)ft_calloc(1, sizeof(t_tools));
	init_env(tools, envp);
	prompt = "\001\033\[95m\002minihell\001\033[0m\002$ ";
	while (1)
	{
		init_sig(tools);
		line = readline(prompt);
		if (g_sig == 130)
		{
			tools->ecode = g_sig;
			g_sig = 0;
		}
		if (!line)
			break ;
		if (*line)
			add_history(line);
		if (checkopenquote(tools, line) && !checkthreesome(line) && \
		!checkdouble_redirect(line) && !setcmds(tools, line))
			(void)(initexecute(tools), freecmdtab(tools->cmdtab));
		free(line);
	}
	return (freeenv(tools->env), free(tools), 0);
}
*/
