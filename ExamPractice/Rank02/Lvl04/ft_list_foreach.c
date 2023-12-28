/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:43:48 by cwan              #+#    #+#             */
/*   Updated: 2023/12/28 09:44:02 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------
Write a function that takes a list and a function pointer, and applies this
function to each element of the list.
It must be declared as follows:
void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
The function pointed to by f will be used as follows:
(*f)(list_ptr->data);
You must use the following structure, and turn it in as a file called
ft_list.h:
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list; */
