/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:11 by cwan              #+#    #+#             */
/*   Updated: 2023/11/21 13:05:14 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trimmedline(char **buffer)
{
	char	*tmpptr;
	char	*trimline;
	int		i;

	i = 0;
	tmpptr = *buffer;
	while ((*buffer)[i] != '\n')
		i++;
	i++;
	trimline = ft_calloc(i + 1, sizeof(char));
	while (i--)
		trimline[i] = (*buffer)[i];
	*buffer = ft_strdup(ft_strchr(*buffer, '\n') + 1);
	return (free(tmpptr), trimline);
}

char	*readnjoin(int fd, char *buffer, int *readbytes)
{
	char	*tmpbuff;
	char	*tmpptr;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	tmpptr = buffer;
	tmpbuff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	*readbytes = read(fd, tmpbuff, BUFFER_SIZE);
	buffer = ft_strjoin(buffer, tmpbuff);
	free(tmpbuff);
	free(tmpptr);
	if (*readbytes < 0 || (!*readbytes && !*buffer))
		return (free(buffer), buffer = NULL, buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*nextline;
	int			readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (ft_strchr(buffer[fd], '\n') == NULL && readbytes)
	{
		buffer[fd] = readnjoin(fd, buffer[fd], &readbytes);
		if (!buffer[fd])
			break ;
	}
	if (ft_strchr(buffer[fd], '\n') != NULL)
		return (trimmedline(&buffer[fd]));
	if (!buffer[fd])
		return (NULL);
	nextline = ft_strdup(buffer[fd]);
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (nextline);
}

#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char *av[])
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			sleep(3);
		}
	}
	else if (ac == 1)
	{
		while ((line = get_next_line(STDIN_FILENO)) != NULL)
			printf("%s", line);
	}
	return(free(line), close(fd), 0);
}
