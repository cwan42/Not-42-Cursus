/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:59 by cwan              #+#    #+#             */
/*   Updated: 2023/10/20 10:57:50 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	t_cleanarray(t_list **list)
{
	t_list	*lastnode;
	t_list	*cleannode;
	int		i;
	int		k;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	cleannode = malloc(sizeof(t_list));
	if (!buffer || !cleannode)
		return ;
	lastnode = findlastnode(*list);
	i = 0;
	k = 0;
	while (lastnode->content[i] && lastnode->content[i] != '\n')
		++i;
	while (lastnode->content[i] && lastnode->content[++i])
		buffer[k++] = lastnode->content[i];
	buffer[k] = '\0';
	cleannode->content = buffer;
	cleannode->next = NULL;
	dealloc(list, cleannode, buffer);
}

char	*get_line(t_list *list)
{
	int		strlen;
	char	*nextstr;

	if (!list)
		return (NULL);
	strlen = tlist_strlen(list);
	nextstr = malloc(strlen + 1);
	if (!nextstr)
		return (NULL);
	copystr(list, nextstr);
	return (nextstr);
}

void	t_addtolist(t_list **list, char *buffer)
{
	t_list	*node;
	t_list	*lastnode;

	lastnode = findlastnode(*list);
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	if (!lastnode)
		*list = node;
	else
		lastnode->next = node;
	node->content = buffer;
	node->next = NULL;
}

int	t_loadlist(t_list **list, int fd)
{
	int		bytesread;
	char	*buffer;

	while (!foundnewline(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (!bytesread)
		{
			free(buffer);
			return (0);
		}
		buffer[bytesread] = '\0';
		t_addtolist(list, buffer);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*buffer = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &nextline, 0) < 0)
		return (NULL);
	t_loadlist(&buffer, fd);
	if (!buffer)
		return (NULL);
	nextline = get_line(buffer);
	t_cleanarray(&buffer);
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
