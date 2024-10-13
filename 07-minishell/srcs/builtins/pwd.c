/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:30 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/20 15:07:54 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_cwd(void)
{
	char	*cwd;
	char	*path;

	cwd = malloc(4096);
	if (!cwd)
		return (perror("malloc"), NULL);
	path = getcwd(cwd, 4096);
	if (!path)
		return (perror("getcwd"), free(cwd), NULL);
	return (cwd);
}

//ft_pwd just prints
int	ft_pwd(t_tools *tools)
{
	char	cwd[4096];
	char	*path;

	path = getcwd(cwd, sizeof(cwd));
	if (!path)
	{
		perror("getcwd");
		return (1);
	}
	printf("%s\n", cwd);
	tools->ecode = 0;
	return (0);
}
