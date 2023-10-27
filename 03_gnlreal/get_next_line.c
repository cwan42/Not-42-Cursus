/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:14:49 by cwan              #+#    #+#             */
/*   Updated: 2023/10/27 18:21:12 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void	t_cleanall

	clean nodes, reinit and keep remainstr
char	*t_getline
	
	copy nodes until \n, return string

void	t_loadnode(int fd, t_list **node)
{
	char	*buffer;
	int		bytesread;

	while (!ft_strchr((*node)->content, '\n'))
	{
		bytesread = read(fd, &buffer, BUFFER_SIZE);
		(*node)->content = malloc(bytesread + 1);
		(*node)->content = buffer; -- need to copy and terminate
		(*node)->content[bytesread + 1] = '\0';
	}	
	ADD TO LIST
		UNTIL \n
	
}

char	*get_next_line(int fd)
{
	static t_list	*node = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &nextline, 0) < 0)
		return (NULL);
	t_loadnode(fd, &node)
}
