/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:40:09 by cwan              #+#    #+#             */
/*   Updated: 2024/05/16 14:50:36 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//ft_cwd returns the cwd as string, reqs freeing
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
void	ft_pwd(void)
{
	char	cwd[4096];
	char	*path;

	path = getcwd(cwd, sizeof(cwd));
	if (!path)
	{
		perror("getcwd");
		return ;
	}
	ft_printf("%s\n", cwd);
}
