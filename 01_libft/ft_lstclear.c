/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:27:43 by cwan              #+#    #+#             */
/*   Updated: 2023/09/14 14:34:09 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temparr;

	while (*lst != NULL)
	{
		temparr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temparr;
	}
	*lst = NULL;
}
