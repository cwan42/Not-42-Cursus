/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:59 by cwan              #+#    #+#             */
/*   Updated: 2023/10/18 19:42:23 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*t_printline(t_list *list)
{
	char	*line;
	int		i;
	int		k;

	line = malloc((tlist_strlen(list)) + 1);
	if (!line)
		return (NULL);
	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				line[k++] = '\n';
				line[k] = '\0';
				return (line);
			}
			line[k++] = list->content[i++];
		}
		list = list->next;
	}
	line[k] = '\0';
	return (line);
}

void	t_addtolist(t_list **list, char *buffer)
{
	t_list	*node;
	t_list	*lastnode;

	node = malloc(sizeof(t_list));
	if (!list || !node)
	{
		free(node);
		return ;
	}
	node->content = buffer;
	node->next = NULL;
	while (*list && (*list)->next)
		*list = (*list)->next;
	lastnode = *list;
	if (!lastnode)
		*list = node;
	else
		lastnode->next = node;
}

int	t_loadnodes(t_list **list, int fd)
{
	int		bytesread;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		bytesread = 0;
		while (!buffer[bytesread])
			bytesread++;
		buffer[bytesread] = '\0';
		t_addtolist(list, buffer);
		if (ft_strchr(buffer, '\n'))
			return (0);
	}
	free(buffer);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*buffer = NULL;
	char			*nextline;
	t_list			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!(t_loadnodes(&buffer, fd)))
		return (NULL);
	nextline = t_printline(buffer);
	while (buffer)
	{
		tmp = buffer;
		buffer = buffer->next;
		free(tmp->content);
		free(tmp);
	}
	return (nextline);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL && argc == 2)
		{
			if (line != NULL)
				printf("%s", line);
			free(line);
		}
	}
	else if (argc == 1)
	{
		while ((line = get_next_line(STDIN_FILENO)) != NULL)
		{
			printf("%s", line);
		}
	}
}*/