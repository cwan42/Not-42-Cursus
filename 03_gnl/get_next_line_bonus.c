/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:30:05 by cwan              #+#    #+#             */
/*   Updated: 2023/10/01 14:28:52 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	nextline = ft_strducpy(bufstr);
	if (!nextline)
		return (NULL);
	return (nextline);
}

char	*ft_readbuffer(int fd, char *bufstr)
{
	char	*buffer;
	int		bytesread;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(bufstr, '\n'))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(bufstr);
			bufstr = NULL;
			free (buffer);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		bufstr = ft_strjoin(bufstr, buffer);
	}
	free(buffer);
	return (bufstr);
}

char	*get_next_line(int fd)
{
	static char	*bufstr = NULL;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bufstr = ft_readbuffer(fd, bufstr);
	if (!bufstr)
		return (NULL);
	nextline = ft_printline(bufstr);
	return (nextline);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int	fd;
	
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	return (0);
}
GNL should return line read, or NULL if nothing to read or error.
Should read from both files and stdin
Line should include \n unless EOF

undefined behaviour if file being read changed before EOF, and if binary file
*/
