/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlcp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:52:53 by cwan              #+#    #+#             */
/*   Updated: 2023/09/29 11:52:34 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "get_next_line.h"

void	polish_list(t_list **list)
{
	t_list	*lastnode;
	t_list	*cleannode;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	cleannode = malloc(sizeof(t_list));
	if (!buf || !cleannode)
		return ;
	lastnode = findlastnode(*list);
	i = 0;
	j = 0;
	while (lastnode->strbuffer[i] && lastnode->strbuffer[i] != '\n')
		++i;
	while (lastnode->strbuffer[i] && lastnode->strbuffer[++i])
		buf[j++] = lastnode->strbuffer[i];
	buf[j] = '\0';
	cleannode->strbuffer = buf;
	cleannode->next = NULL;
	dealloc(list, clean_node, buf);
}

void	copystr(t_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->strbuffer[i])
		{
			if (list->strbuffer[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->strbuffer[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->strbuffer[i])
		{
			if (list->strbuffer[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

char	*ft_getline(t_list *list)
{
	int		strlen;
	char	*nextstr;

	if (!list)
		return (NULL);
	strlen = len_to_newline(list);
	nextstr = malloc(strlen + 1);
	if (!nextstr)
		return (NULL);
	copystr(list, nextstr);
	return (nextstr);
}

void	ft_append(t_list **list, char *buf)
{
	t_list	*newnode;
	t_list	*lastnode;

	lastnode = ft_findlastnode(*list);
	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return ;
	if (!lastnode)
		*list = newnode;
	else
		lastnode->next = newnode;
	newnode->strbuffer = buf;
	newnode->next = NULL;
}

void	ft_createlist(t_list **list, int fd)
{
	int		charread;
	char	*buf;

	while (!foundnewline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		charread = read(fd, buf, BUFFER_SIZE);
		if (!charread)
		{
			free(buf);
			return ;
		}
		buf[charread] = '\0';
		ft_append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*nextline;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &nextline, 0) < 0)
		return (NULL);
	ft_createlist(&list, fd);
	if (!list)
		return (NULL);
	nextline = ft_getline(list);
	polishlist(&list);
	return (nextline);
}
/*
char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	size_t	linelen;
	size_t	buffersize;
	ssize_t	bytes_read;

	line = NULL;
	line = malloc(buffersize);
	if (line == NULL)
		return (NULL);
	while (1)
	{
		bytes_read == read(fd, &c, 1);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		else if (bytes_read == 0)
		{
			if (linelen == 0)
			{
				free(line);
				return (NULL);
			}
		}
		else
			break ;
	}
}

PROTOTYPE

	int	filedescriptor;
	char buffer[1024];
//to open
	filedescriptor = open("FILENAME.txt", 0_RDONLY);
	if (filedescriptor == -1)
	{
		perror("Error opening file");
		return (1);
	}
//to read
	ssize_t	bytes_read = read(filedescriptor, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		perror("Error reading file");
		close(filedescriptor);
		return (1);
	}
	close(filedescriptor);
	return (0);
*/
