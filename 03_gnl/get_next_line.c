/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:30:05 by cwan              #+#    #+#             */
/*   Updated: 2023/10/03 12:55:07 by cwan             ###   ########.fr       */
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
		bufstr = NULL;
		return (NULL);
	}
	toclear++;
	len = ft_strlen(toclear);
	remainstr = malloc(sizeof(char) * (len));
	if (!remainstr)
		return (NULL);
	ft_strlcpy(remainstr, toclear, len + 1);
	free(bufstr);
	bufstr = NULL;
	free(remainstr);
	return (remainstr);
}

char	*ft_printline(char *bufstr)
{
	char	*nextline;
	int		i;

	i = 0;
	if (!*bufstr)
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
	while (!ft_strchr(bufferstr, '\n') && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(bufferstr);
			bufferstr = NULL;
			free(buffer);
			return (NULL);
		}
		if (bytesread > 0)
		{
			buffer[bytesread] = '\0';
			bufferstr = ft_strjoin(bufferstr, buffer);
		}
	}
	free(buffer);
	return (bufferstr);
}

char	*get_next_line(int fd)
{
	static char	*bufferstr = NULL;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bufferstr = ft_readbuffer(fd, bufferstr);
	if (!bufferstr)
		return (NULL);
	nextline = ft_printline(bufferstr);
	ft_clearbuf(bufferstr);
	return (nextline);
}
/*
#include <stdio.h>
#include <fcntl.h>

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
*/
