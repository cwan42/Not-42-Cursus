/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:59 by cwan              #+#    #+#             */
/*   Updated: 2023/10/17 09:26:31 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

PRINT from nodes until newline
memmove or cleannode to retain remaining as first node
free everything
char	*t_printline(t_list *list)
{
	char	*line;

	if (!list)
		return (NULL);
	STRLEN TO NEWLINE
	if (!line)
		return (NULL);
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
	while ((*list)->next)
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
		bytesread = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesread] = '\0';
		t_addtolist(list, buffer);
		if (ft_strchr(buffer, '\n'))
			return (0) ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*buffer = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!(t_loadnodes(&buffer, fd)))
		return (NULL);
	return (nextline);
}
/*
#include <stdio.h>
#include <fcntl.h>

void	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL && argc == 2)
			printf("%s", line);
	}
	else if (argc == 1)
	{
		while ((line = get_next_line(STDIN_FILENO)) != NULL)
			printf("%s", line);
			free(line);
	}
}
*/
