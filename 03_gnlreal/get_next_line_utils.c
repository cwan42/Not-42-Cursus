/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:38:44 by cwan              #+#    #+#             */
/*   Updated: 2023/11/02 15:53:45 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	t_findnewline(t_list *node)
{
	int	i;

	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (node->content[i] && node->content[i] != '\n')
		{
			if (node->content[i] == '\n')
				return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}

int	ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (1);
		str++;
	}
	return (0);
}

void	resetnodes(t_list **node)
{
	t_list	*remnantnode;
	t_list	*lastnode;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	remnantnode = malloc(sizeof(t_list));
	if (!buffer || !remnantnode)
		return ;
	lastnode = *node;
	while (lastnode->next)
		lastnode = lastnode->next;
	i = 0;
	j = 0;
	while (lastnode->content[i] && lastnode->content[i] != '\n')
		++i;
	while (lastnode->content[i])
		buffer[j++] = lastnode->content[i];
	buffer[j] = '\0';
	remnantnode->content = buffer;
	remnantnode->next = NULL;
	dealloc(node, remnantnode, buffer);
}

void	dealloc(t_list **list, t_list *cleannode, char *buffer)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (cleannode->content[0])
		*list = cleannode;
	else
	{
		free(buffer);
		free(cleannode);
	}
}
