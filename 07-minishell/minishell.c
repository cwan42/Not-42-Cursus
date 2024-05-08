/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:30 by cwan              #+#    #+#             */
/*   Updated: 2024/05/08 18:14:41 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_tools
{
	int	simplecmds;
}		t_tools;

int	inittools(t_tools *tools)
{
	tools->simplecmds = 0;
	return (1);
}

int	minishellloop(t_tools tools)
{
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	ft_printf("Test minishell launched");
	inittools(&tools);
	minishellloop(&tools);
	return (0);
}
