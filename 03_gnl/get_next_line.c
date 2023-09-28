/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:30:05 by cwan              #+#    #+#             */
/*   Updated: 2023/09/28 10:46:51 by cwan             ###   ########.fr       */
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
/*
FN createlist/lstnew?
read fd and store info by buf
lstadd back until EOL?
return length? needed?
copy and print line as string
clean up on aisle 6.

char	*get_next_line(int fd)
PROTOTYPE
SAFETY CHECK if no fd or buf or read fail
create t_list with fd
populate with lines, delimited by \n or buf?
print line, ensure read moves to next line?

GNL should return line read, or NULL if nothing to read or error.
Should read from both files and stdin
Line should include \n unless EOF

undefined behaviour if file being read changed before EOF, and if binary file
*/
