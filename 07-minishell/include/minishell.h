/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:26 by cwan              #+#    #+#             */
/*   Updated: 2024/05/14 17:05:35 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_tools
{
	char	**cmds;
	t_list	**env;
	int		tokens;
}			t_tools;

void ft_pwd(void);

void	init_env(t_tools *tools, char **envp);
void    print_env(t_tools *tools);

int		exithell(t_tools *tools);

void	addtohist(t_tools *tools, char *line);
void	init_hist(t_tools *tools);

#endif
