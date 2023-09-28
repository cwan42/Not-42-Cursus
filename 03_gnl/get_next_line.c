/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:30:05 by cwan              #+#    #+#             */
/*   Updated: 2023/09/28 17:03:34 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_maxfd()
{
	long	maxfd;

	maxfd = sysconf(_SC_OPEN_MAX);
	if (maxfd < 0)
		exit (EXIT_FAILURE);
	return ((int)maxfd);
}

t_list ft_lstlastadd(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;	
}

t_list	*ft_lstnew(void *content, fd)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(BUFFER_SIZE + 1);
	if (!newlist)
		return (NULL);
	newlist->strbuf = content;
	newlist->next = NULL;
	return (newlist);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*nextline;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &nextline, 0)
		return (NULL);
	ft_listnew(&list, fd);
	if (!list)
		return (NULL);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	fd;
	
	fd = open(argv[1], 0_RDONLY);
	while (get_next_line(fd) != 0);
		;
	close(fd);
	return (0);
}
/*
FN createlist/lstnew?
read fd and store info by buf
lstadd back until EOL?
return length? needed?
copy and print line as string
clean up on aisle 6.

create t_list with fd
populate with lines, delimited by \n or buf?
print line, ensure read moves to next line?

GNL should return line read, or NULL if nothing to read or error.
Should read from both files and stdin
Line should include \n unless EOF

undefined behaviour if file being read changed before EOF, and if binary file
*/
