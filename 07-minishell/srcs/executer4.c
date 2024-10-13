/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:35:08 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/27 18:03:35 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	waitloop(t_tools *tools)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (tools->ppid[i])
	{
		waitpid(tools->ppid[i], &status, 0);
		{
			if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status) == SIGINT)
					(void)(ft_putstr_fd("\n", 1), tools->ecode = 130);
				else if (WTERMSIG(status) == SIGQUIT)
					tools->ecode = 131;
				else if (status != 13)
					tools->ecode = 256 % (128 + WTERMSIG(status));
			}
			else if (WIFEXITED(status))
				tools->ecode = WEXITSTATUS(status);
			tools->ppid[i] = 0;
			i++;
		}
	}
}

int	checkheredoc(t_tools *tools)
{
	handle_null_cmds(tools, *tools->cmdtab);
	if (hasheredoc(tools))
	{
		if (createheredocs(tools))
			return (1);
	}
	return (0);
}

void	init2(t_tools *tools, int *input_fd)
{
	if (*input_fd != 0)
		close(*input_fd);
	waitloop(tools);
	init_sig(tools);
}

int	initexecute(t_tools *tools)
{
	t_cmd	*tmp;
	int		pipefd[2];
	int		input_fd;

	tmp = *tools->cmdtab;
	input_fd = 0;
	if (checkheredoc(tools))
		return (0);
	while (tmp)
	{
		if (tmp->n != NULL)
		{
			if (pipe(pipefd) == -1)
				return (quietquit(tools), 1);
		}
		if (!handle_command(tools, tmp))
		{
			if (isbuiltin(tmp->cmds[0]) && !(*tools->cmdtab)->n)
				fakeparser(tools, tmp);
			else if (execute_command(tools, tmp, &input_fd, pipefd))
				break ;
		}
		tmp = tmp->n;
	}
	return (init2(tools, &input_fd), 0);
}
