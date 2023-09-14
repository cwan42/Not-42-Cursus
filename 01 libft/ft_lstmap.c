/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:21:20 by cwan              #+#    #+#             */
/*   Updated: 2023/09/14 17:28:43 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	if (!lst || !*f || !*del)
		return (0);
	newlist = ft_lst_new(f(lst->content));
	while (lst->next)
	{
		lst = lst->next;
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
				ft_lstclear(*newlist, del);
				return (0);
		}
		ft_lstadd_back(&newlist, newnode);
	}
	return (newlist);
}
