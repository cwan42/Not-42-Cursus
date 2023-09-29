/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:30:05 by cwan              #+#    #+#             */
/*   Updated: 2023/09/29 15:40:04 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_maxfd(void)
{
	long	maxfd;

	maxfd = sysconf(_SC_OPEN_MAX);
	if (maxfd < 0)
		exit (EXIT_FAILURE);
	return ((int)maxfd);
}

t_list	ft_lstlastadd(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}

char	*get_next_line(int fd)
{
	static char	*bufstr;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &nextline, 0))
		return (NULL);
	bufstr = 
	
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int	fd;
	
	fd = open(argv[1], 0_RDONLY);
	while (get_next_line(fd) != 0);
		;
	close(fd);
	return (0);
}

GNL should return line read, or NULL if nothing to read or error.
Should read from both files and stdin
Line should include \n unless EOF

undefined behaviour if file being read changed before EOF, and if binary file
*/
