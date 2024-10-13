/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:01:53 by cwan              #+#    #+#             */
/*   Updated: 2024/09/29 23:06:15 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hasheredoc(t_tools *tools)
{
	t_cmd	*tmp;
	int		i;

	tmp = *tools->cmdtab;
	while (tmp)
	{
		i = 0;
		while (tmp->rd[i])
		{
			if (!ft_strcmp(tmp->rd[i], "<<") && tmp->rd[i + 1])
				return (1);
			i++;
		}
		tmp = tmp->n;
	}
	return (0);
}

void	closeunlinkmult(t_tools *tools)
{
	int	i;

	tools->ecode = 130;
	g_sig = 0;
	i = 0;
	while (i <= 10)
	{
		if (tools->dfd[i])
		{
			close(tools->dfd[i]);
			unlink(tools->hdname[i]);
		}
		i++;
	}
}

int	writeheredoc(t_tools *tools, int d)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	tools->dfd[d] = open(tools->hdname[d], O_CREAT | O_RDWR | O_TRUNC, 0644);
	init_heredocsig();
	while (1)
	{
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
		if (g_sig == 130)
			return (closeunlinkmult(tools), printf("\n"), -1);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (ft_strncmp(buffer, tools->delimiters[d], \
			ft_strlen(tools->delimiters[d])) == 0 && \
			buffer[ft_strlen(tools->delimiters[d])] == '\n')
			break ;
		if (write(tools->dfd[d], buffer, bytes_read) == -1)
			return (close(tools->dfd[d]), unlink(tools->hdname[d]), -1);
	}
	return (close(tools->dfd[d]), 0);
}

void	renamehd(t_tools *tools, t_cmd *tmp, int d, int i)
{
	if (tools->hdname[d])
		free(tools->hdname[d]);
	tools->hdname[d] = ft_strjoin("/tmp/hd", tmp->rd[i + 1]);
}

int	createheredocs(t_tools *tools)
{
	t_cmd	*tmp;
	int		i;
	int		d;

	d = 0;
	tmp = *tools->cmdtab;
	while (tmp)
	{
		i = 0;
		while (tmp->rd && tmp->rd[i])
		{
			if (!ft_strcmp(tmp->rd[i], "<<"))
			{
				tools->delimiters[d] = (tmp->rd[i + 1]);
				renamehd(tools, tmp, d, i);
				if (!tools->delimiters[d] || writeheredoc(tools, d) == -1)
					return (init_sig(tools), 1);
				d++;
			}
			i += 2;
		}
		tmp = tmp->n;
	}
	return (init_sig(tools), 0);
}
