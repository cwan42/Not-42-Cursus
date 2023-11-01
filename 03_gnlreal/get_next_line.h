/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:06:03 by cwan              #+#    #+#             */
/*   Updated: 2023/10/27 17:40:51 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*ft_strchr(const char *str, int c);
void	resetnodes(t_list **node);
void	dealloc(t_list **list, t_list *cleannode, char *buffer);

void	copynodes(t_list *node, char *line);
char	*printline(t_list *node);
void	t_addbynode(char *buffer, t_list **node);
void	t_loadnode(int fd, t_list **node);
char	*get_next_line(int fd);
#endif
