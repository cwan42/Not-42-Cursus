/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:59 by cwan              #+#    #+#             */
/*   Updated: 2023/10/14 05:19:18 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

void	t_cleanlist(t_list **list)
{
	t_list	*lastnode;
	t_list	*cleannode;
	int		i;
	int		j;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	cleannode = malloc (sizeof(t_list));
	if (!buff || !cleannode)
		return ;
	while ((*list)->next)
		*list = (*list)->next;
	lastnode = *list;
	i = 0;
	j = 0;
	while (lastnode->content[i] != '\0' && lastnode->content[i] != '\n')
		i++;
	while (lastnode->content[i] && lastnode->content[++i])
		buff[j++] = lastnode->content[i];
	buff[j] = '\0';
	cleannode->content = buff;
	cleannode->next = NULL;
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

int	t_findnewline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	t_loadlist(t_list **list, int fd)
{
	int		bytesread;
	char	*buffer;

	while (!t_findnewline(*list))
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
		t_bufftoline(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	t_loadlist(&list, fd);
	if (!list)
		return (NULL);
	nextline = t_getline(list);
	t_cleanlist(&list);
	return (nextline);
}
/*
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL && argc == 2)
	{
		printf("%s", line);
		sleep(1);
	}
	return (0);
}
*/
