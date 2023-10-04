/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:59 by cwan              #+#    #+#             */
/*   Updated: 2023/10/04 14:35:47 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

void	t_clearlist(t_list **list)
{
}

void	t_bufftoline(t_list **list, char *buffer)
{
	t_list	*newnode;
	t_list	*lastnode;

	if (!*list)
		return ;
	while ((*list)->next)
		*list = (*list)->next;
	lastnode = *list;
	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return ;
	if (!lastnode)
		*list = newnode;
	else
		lastnode->next = newnode;
	newnode->content = buffer;
	newnode->next = NULL;
}

void	t_loadlist(t_list **list, int fd)
{
	int		bytesread;
	char	*buffer;

	while (!t_findnewline(*list))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (!bytesread)
		{
			free(buffer);
			return ;
		}
		buffer[bytesread] = '\0';
		t_bufftoline(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &nextline, 0) < 0)
		return (NULL);
	t_loadlist(&list, fd);
	if (!list)
		return (NULL);
	nextline = malloc(ft_strlen(list->content) + 1);
	ft_strlcpy(nextline, list->content, ft_strlen(nextline));
	t_clearlist(&list);
	return (nextline);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd) != NULL)
	{
		printf("%s", get_next_line(fd));
		sleep(1);
	}
	return (0);
}

