/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:26 by cwan              #+#    #+#             */
/*   Updated: 2024/05/17 12:29:46 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

//for type: 1 <; 2 <<; 3 cmd; 4 param; 5 "; 6 '; 7 |; 8 >; 9 >>
typedef struct s_tools
{
	t_list	**env;
	char	**cmds;
	int		*type;
	int		ecode;
	int		tokens;
}			t_tools;

//builtins - echo

//builtins - cd
int		cd(t_tools *tools);

//builtins - env
void	init_env(t_tools *tools, char **envp);
void	print_env(t_tools *tools);

//builtins - exit
void	freearr(char **arr);
void	freelist(t_list **lst);
int		exithell(t_tools *tools);

//builtins - pwd
char	*ft_cwd(void);
void	ft_pwd(void);

#endif
