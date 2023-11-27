/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:27:43 by cwan              #+#    #+#             */
/*   Updated: 2023/09/19 10:19:56 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temptr;

	while (*lst != NULL)
	{
		temptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temptr;
	}
	*lst = NULL;
}
