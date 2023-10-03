/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:59 by cwan              #+#    #+#             */
/*   Updated: 2023/10/03 17:28:34 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

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
		APPEND!
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
	nextline = 
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
