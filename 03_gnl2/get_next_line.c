/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:11 by cwan              #+#    #+#             */
/*   Updated: 2023/11/17 12:21:55 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trimmedline(char **buffer);

char	*readnjoin(char *buffer, int fd)
{
	char	*tmpbuff;
	int		readbytes;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	tmpbuff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readbytes = read(fd, tmpbuff, BUFFER_SIZE);
	if (readbytes < 1)
	{
		if (readbytes == 0)
			return (free(tmpbuff), buffer);
		else
			return (free(buffer), free(tmpbuff), NULL);
	}
	buffer = ft_strjoin(buffer, tmpbuff);
	return (free(tmpbuff), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*nextline;
	char		*tmpptr;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (!(ft_strchr(buffer[fd], '\n')))
		buffer[fd] = readnjoin(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
//	if (ft_strchr(buffer[fd], '\n'))
//		return(trimmedline(&buffer[fd]));STOPPED HERE
	return(buffer[fd]);
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
			printf("%s", line);
			sleep(3);
	}
	else if (ac == 1)
	{
		while ((line = get_next_line(STDIN_FILENO)) != NULL)
			printf("%s", line);
	}
	else
	{
		printf("Error opening file");
		return (1);
	}
	return(free(line), close(fd), 0);
}
