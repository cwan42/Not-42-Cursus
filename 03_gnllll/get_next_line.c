/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:59 by cwan              #+#    #+#             */
/*   Updated: 2023/10/16 12:09:39 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

LOAD TO NODES until newline
PRINT from nodes until newline
memmove or cleannode to retain remaining as first node
free everything
void	t_loadnodes(t_list **list, int fd)
{
	int		bytesread;
	char	*buffer;
	
	buffer = malloc(sizeof(char) * (BUFFERSIZE + 1));
	if (!buffer)
		return ;
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (!bytesread)
	{
		free(buffer);
		return;
	}
	buffer[bytesread] = '\0';
}

char	*get_next_line(int fd)
{
	static t_list	*buffer = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE < 1 )
		return (NULL);
	t_loadnodes(&buffer, fd);
	if (!buffer)
		return (NULL);
	nextline = t_getline(buffer);
	t_cleanbuffer(&buffer);
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
