/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:11 by cwan              #+#    #+#             */
/*   Updated: 2023/11/15 05:32:34 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clearbuffer(char *buffer, int len)
{
	char	*temp;
	
	if (!ft_strchr(buffer, '\n'))
		return(free(buffer), NULL);
	temp = malloc(len * sizeof(char));	
	ft_strlcpy(temp, ft_strchr(buffer, '\n'), len + 1);
	return (free(buffer), temp);
}

char	*readnjoin(char *buffer, int fd)
{
	char	*tmpbuff;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	tmpbuff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (read(fd, tmpbuff, BUFFER_SIZE) < 1)
	{
		if (read(fd, tmpbuff, BUFFER_SIZE) == 0)
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
	int			trimlen;

	if (fd < 0 || BUFFER_SIZE < 1 )
//|| read(fd, &nextline, 0) == -1)
		return (NULL);
	while (!(ft_strchr(buffer[fd], '\n')) && buffer[fd])
		buffer[fd] = readnjoin(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	if (ft_strchr(buffer[fd], '\n'))
	{
		trimlen = ft_strchr(buffer[fd], '\n') - buffer[fd] + 1;
		nextline = malloc(trimlen + 1);
		if (!nextline)
			return (NULL);
		ft_strlcpy(nextline, buffer[fd], trimlen + 1);
//	buffer[fd] = clearbuffer(buffer[fd], trimlen + 1);
		return (nextline);
	}
	else
		return (buffer[fd]);
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
}
