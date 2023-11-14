/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:11 by cwan              #+#    #+#             */
/*   Updated: 2023/11/14 17:22:09 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleanup(char *mainstr)
{
	char	*toclean;
	char	*tokeep;
	size_t	len;

	toclean = ft_strchr(mainstr, '\n');
	if (!toclean)
		return (free(mainstr), NULL);
	toclean++;
	len = ft_strlen(toclean);
	tokeep = ft_calloc(len + 1, sizeof(char));
	if (!tokeep)
		return (NULL);
	while (*toclean)
		*tokeep++ = *toclean++;
	free(mainstr);
	mainstr = NULL;
	return (tokeep);	
}

char	*nextline(char *mainstr)
{
	char	*nextline;
	int		i;
	int		j;

	i = 0;
	if (!mainstr)
		return (NULL);
	while (mainstr[i] && mainstr[i] != '\n')
		i++;
	if (ft_strchr(mainstr, '\n'))
		i++;
	nextline = ft_calloc(i + 1, sizeof(char));
	if (!nextline)
		return (NULL);
	j = 0;
	while (j < i)
	{
		nextline[j] = mainstr[j];
		j++;
	}
	return (nextline);
}

char	*readnjoin(char *mainstr, int fd)
{
	char	*curbuffer;
	int		bytesread;

	if (!mainstr)
		mainstr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	curbuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(mainstr, '\n') && bytesread > 0)
	{
		bytesread = read(fd, curbuffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (free(mainstr), free(curbuffer), NULL);
		mainstr = ft_strjoin(mainstr, curbuffer);
	}
	return (free(curbuffer), mainstr);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*theline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (!(ft_strchr(buffer[fd], '\n')))
	{
		buffer[fd] = readnjoin(buffer[fd], fd);
		if (!buffer[fd])
			break ;
	}
//	if (ft_strchr(buffer[fd], '\n')
//	return (
	if (!buffer[fd])
		return (NULL);
	theline = nextline(buffer[fd]);
	buffer[fd] = cleanup(buffer[fd]);
	return (theline);
}

/*
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, sizeof(char));
	buffer[fd] = readnjoin(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	theline = nextline(buffer[fd]);
	buffer[fd] = cleanup(buffer[fd]);
	return (theline);
}*/

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
