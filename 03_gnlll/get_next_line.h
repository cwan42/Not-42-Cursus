/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:16:45 by cwan              #+#    #+#             */
/*   Updated: 2023/10/14 05:21:44 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		t_lentonewline(t_list *list);
int		t_findnewline(t_list *list);
char	*t_getline(t_list *list);
void	t_freebuffer(t_list *list);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);

char	*get_next_line(int fd);

#endif
