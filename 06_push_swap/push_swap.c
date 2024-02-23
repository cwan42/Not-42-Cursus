/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:04 by cwan              #+#    #+#             */
/*   Updated: 2024/02/23 17:39:10 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack *list = NULL;
	t_stack	*newnode;
//	t_list	*temp = 0;
	int		array[] = {3, 5, 2, 1, 4};
	int		i = 0;

	while (i < 5)
	{
		newnode = ft_stknew(array[i]);
		if (!list)
			list = newnode;
		else
		{
			
		}
	}
}
