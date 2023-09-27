/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:46:27 by cwan              #+#    #+#             */
/*   Updated: 2023/09/27 10:35:32 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*strbuffer;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

#endif
