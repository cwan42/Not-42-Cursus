/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:46:27 by cwan              #+#    #+#             */
/*   Updated: 2023/12/28 11:48:59 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	int	size = ac - 1;
	int	*tab = malloc(size * sizeof(int));
	int	i = 0;

	while (i < size)
	{
		tab[i] = atoi(av[i + 1]);
		i++;
	}
	i = 0;
	while (i < size)
		printf("%d ", tab[i++]);
	printf("\n");
	sort_int_tab(tab, size);
	i = 0;
	while (i < size)
		printf("%d ", tab[i++]);
	return (printf("\n"), free(tab), 0);
}
*/
/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------
Write the following function:
void sort_int_tab(int *tab, unsigned int size);
It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.
Doubles must be preserved.
Input is always coherent. */
