/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:14:49 by cwan              #+#    #+#             */
/*   Updated: 2023/11/02 16:58:52 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copynodes(t_list *node, char *line)
{
	int	i;

	if (!node)
		return ;
	while (node)
	{
		i = 0;
		while (node->content[i] && node->content[i] != '\n')
		{
			line[i] = node->content[i];
			i++;
		}
		if (node->content[i] == '\n')
			line[i++] = '\n';
		node = node->next;
	}
	line[i] = '\0';
}

char	*printline(t_list *node)
{
	int		i;
	int		len;
	char	*line;

	if (!node)
		return (NULL);
	len = 0;
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			if (node->content[i] == '\n')
				len += i + 1;
			i++;
		}
		len += i;
		node = node->next;
	}
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	copynodes(node, line);
	return (line);
}

void	t_addbynode(char *buffer, t_list **node)
{
	t_list	*lastnode;
	t_list	*activenode;

	if (!(*node))
		lastnode = NULL;
	else
	{
		lastnode = *node;
		while (lastnode->next)
			lastnode = lastnode->next;
	}
	activenode = malloc(sizeof(t_list));
	if (!activenode)
		return ;
	activenode->content = buffer;
	activenode->next = NULL;
	if (!lastnode)
		*node = activenode;
	else
		lastnode->next = activenode;
}

void	t_loadnode(int fd, t_list **node)
{
	char	*buffer;
	int		bytesread;

	while (!t_findnewline(*node))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (!bytesread)
		{
			free(buffer);
			return ;
		}
		buffer[bytesread] = '\0';
		t_addbynode(buffer, node);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*node = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &nextline, 0) < 0)
		return (NULL);
	t_loadnode(fd, &node);
	if (!node)
		return (NULL);
	nextline = printline(node);
	resetnodes(&node);
	return (nextline);
}
/*
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (((line = get_next_line(fd)) != NULL) && argc == 2)
			printf("%s", line);
	}
	else if (argc == 1)
	{
		while ((line = get_next_line(STDIN_FILENO)) != NULL)
			printf("%s", line);
	}
}
*/
