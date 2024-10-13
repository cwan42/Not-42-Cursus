/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:07:05 by cwan              #+#    #+#             */
/*   Updated: 2024/10/12 12:51:25 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_cmd_and_str(char *cmd, char *str)
{
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
	}
}

void	errmsg(char *cmd, char *str, int type)
{
	print_cmd_and_str(cmd, str);
	if (type == 1)
		ft_putstr_fd("No such file or directory\n", 2);
	else if (type == 2)
		ft_putstr_fd("command not found\n", 2);
	else if (type == 3)
		ft_putstr_fd("Permission denied\n", 2);
	else if (type == 4)
		ft_putstr_fd("Is a directory\n", 2);
	else if (type == 5)
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
	else if (type == 6)
		ft_putstr_fd("syntax error near unexpected token `>'\n", 2);
	else if (type == 7)
		ft_putstr_fd("syntax error near unexpected token `<'\n", 2);
	else if (type == 8)
		ft_putstr_fd("syntax error near unexpected token '|'\n", 2);
	else if (type == 99)
		ft_putstr_fd("not a valid identifier\n", 2);
	else if (type == 666)
		ft_putstr_fd("DEBUGGER BOING BOING\n", 2);
}
