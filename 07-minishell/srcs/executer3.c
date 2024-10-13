/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:45:22 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/27 15:48:48 by cbandara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	paircount(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i % 2);
}

void	execute_child(t_tools *tools, t_cmd *cmd, int *input_fd, int *pipefd)
{
	if (cmd->n != NULL)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			perror("dup2 stdout");
			exit(1);
		}
		close(pipefd[0]);
		close(pipefd[1]);
	}
	if (*input_fd != 0)
	{
		if (dup2(*input_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 stdin");
			exit(1);
		}
		close(*input_fd);
	}
	execmd(tools, cmd);
	quietquit(tools);
}

int	execute_parent(t_cmd *cmd, int *input_fd, int *pipefd)
{
	if (cmd->n != NULL)
	{
		close(pipefd[1]);
		if (*input_fd != 0)
			close(*input_fd);
		*input_fd = pipefd[0];
	}
	else
	{
		if (*input_fd != 0)
		{
			close(pipefd[0]);
			close(pipefd[1]);
			close(*input_fd);
		}
	}
	return (0);
}

int	execute_command(t_tools *tools, t_cmd *cmd, int *input_fd, int *pipefd)
{
	int		result;
	int		i;

	i = 0;
	while (tools->ppid[i] > 0)
		i++;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, handlesigquit);
	tools->ppid[i] = fork();
	if (tools->ppid[i] == 0)
	{
		init_childsig();
		execute_child(tools, cmd, input_fd, pipefd);
	}
	else if (tools->ppid[i] > 0)
	{
		result = execute_parent(cmd, input_fd, pipefd);
		if (result == -1)
			return (-1);
	}
	else
		return (perror("fork"), -1);
	return (tools->ecode);
}

int	handle_command(t_tools *tools, t_cmd *cmd)
{
	if (paircount(cmd->rd))
	{
		tools->ecode = 2;
		printf("minihell: syntax error near unexpected token `newline'\n");
		return (1);
	}
	return (tools->ecode = 0, 0);
}
