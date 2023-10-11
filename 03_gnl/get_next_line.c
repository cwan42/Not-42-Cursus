/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:30:05 by cwan              #+#    #+#             */
/*   Updated: 2023/10/11 10:17:25 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*bufferstr[1024];
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bufferstr[fd])
	{
		bufferstr[fd] = malloc(1);
		bufferstr[fd][0] = '\0';
	}
	bufferstr[fd] = ft_readbuffer(fd, bufferstr[fd]);
	if (!bufferstr[fd])
		return (NULL);
	nextline = ft_printline(bufferstr[fd]);
	bufferstr[fd] = ft_clearbuf(bufferstr[fd]);
	return (nextline);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd) != NULL && argc == 2)
	{
		printf("%s", get_next_line(fd));
		sleep(1);
	}		
	return (0);
}
*/
