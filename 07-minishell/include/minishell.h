/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:26 by cwan              #+#    #+#             */
/*   Updated: 2024/05/15 12:17:59 by cwan             ###   ########.fr       */
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

//builtins - cd
int		cd(t_tools *tools);

//builtins - env
void	init_env(t_tools *tools, char **envp);
void    print_env(t_tools *tools);

//builtins - exit
void	freearr(char **arr);
void	freelist(t_list **lst);
int		exithell(t_tools *tools);

//builtins - pwd
void ft_pwd(void);

#endif
