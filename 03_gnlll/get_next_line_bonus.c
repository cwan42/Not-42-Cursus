/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:30:05 by cwan              #+#    #+#             */
/*   Updated: 2023/10/26 13:25:47 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_clearbuf(char *bufstr)
{
	char	*toclear;
	char	*remainstr;
	size_t	len;

	toclear = ft_strchr(bufstr, '\n');
	if (!toclear)
	{
		free(bufstr);
		return (NULL);
	}
	toclear++;
	len = ft_strlen(toclear);
	remainstr = malloc(sizeof(char) * (len + 1));
	if (!remainstr)
		return (NULL);
	ft_strlcpy(remainstr, toclear, len + 1);
	free(bufstr);
	bufstr = NULL;
	return (remainstr);
}

char	*ft_printline(char *bufstr)
{
	char	*nextline;
	int		i;

	i = 0;
	if (!bufstr[0])
		return (NULL);
	while (bufstr[i] && bufstr[i] != '\n')
		i++;
	if (ft_strchr(bufstr, '\n'))
		i++;
	nextline = malloc(sizeof(char) * (i + 1));
	if (!nextline)
		return (NULL);
	ft_strlcpy(nextline, bufstr, i + 1);
	return (nextline);
}

char	*ft_readbuffer(int fd, char *bufferstr)
{
	char	*buffer;
	int		bytesread;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(bufferstr, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(bufferstr);
			free(buffer);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		bufferstr = ft_strjoin(bufferstr, buffer);
	}
	free(buffer);
	return (bufferstr);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(1);
		buffer[fd][0] = '\0';
	}
	buffer[fd] = ft_readbuffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	nextline = ft_printline(buffer[fd]);
	buffer[fd] = ft_clearbuf(buffer[fd]);
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
			printf("%s", line);
	}
	else if (argc == 1)
	{
		while ((line = get_next_line(STDIN_FILENO)) != NULL)
			printf("%s", line);
	}
}
*/
