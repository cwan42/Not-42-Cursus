/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:34:11 by cwan              #+#    #+#             */
/*   Updated: 2023/10/19 15:37:14 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int		foundnewline(t_list *list);
t_list	*findlastnode(t_list *list);
void	copystr(t_list *list, char *str);
char	*ft_strchr(const char *str, int c);
int		tlist_strlen(t_list *list);
void	dealloc(t_list **list, t_list *cleannode, char *buffer);

void	t_cleanarray(t_list **list);
char	*get_line(t_list *list);
char	*t_printline(t_list *list);
void	t_addtolist(t_list **list, char *buffer);
int		t_loadnodes(t_list **list, int fd);
void	createlist(t_list **list, int fd);
char	*get_next_line(int fd);

#endif
