/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:33:22 by cwan              #+#    #+#             */
/*   Updated: 2024/05/31 13:03:53 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd)
{
	static char	buffer[666666] = {'\0'};
	static int	i = 0;
	int			j = 0;
	int			bytesread = 1;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytesread > 0)
	{
		bytesread = read(fd, &buffer[j], BUFFER_SIZE);
		if (bytesread == -1 || !buffer[i])
			return (NULL);
		j += bytesread;
	}
	bytesread = 0;
	while (buffer[i + bytesread] && buffer[i + bytesread] != '\n')
		bytesread++;
	line = malloc(bytesread + 1 + (buffer[i + bytesread] == '\n'));
	if (!line)
		return (NULL);
	line[bytesread + (buffer[i + bytesread] == '\n')] = '\0';
	j = 0;
	while (j <= bytesread)
		line[j++] = buffer[i++];
	return (line);
}

/*
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
			free(line);
		}
	}
	else if (ac == 1)
	{
		while ((line = get_next_line(STDIN_FILENO)) != NULL)
			printf("%s", line);
	}
	return (0);
}*/

/*
Assignment name : get_next_line
Expected files : get_next_line.c (42_EXAM can't take .h for now)
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------
Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);

Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line(). Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.
*/
