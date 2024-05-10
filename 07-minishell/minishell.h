/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:26 by cwan              #+#    #+#             */
/*   Updated: 2024/05/10 12:42:02 by cwan             ###   ########.fr       */
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
	char	*argline;
	t_list	**env;
	int		simplecmds;
}			t_tools;

void ft_pwd(void);

void	init_env(t_tools *tools, char **envp);
void    print_env(t_tools *tools);

#endif
