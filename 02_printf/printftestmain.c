/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftestmain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:31:39 by cwan              #+#    #+#             */
/*   Updated: 2023/10/02 13:51:05 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	str[200];
	int		nbr;

	while (1)
	{
		printf("Enter a string or number, or type END to end the program: ");
		scanf("%199s", str);
		if (strncmp(str, "END", 4) == 0)
			break ;
		nbr = atoi(str);
		ft_printf("Char:%c\tString:%s\n", *str, str);
		printf("Real:%c\tReal: %s\n", *str, str);
		ft_printf("Pointer\t%p", str);
		printf(" : %p\n", str);
		ft_printf("Decimal\t%d", nbr);
		printf(" : %d\n", nbr);
		ft_printf("Integer\t%i", nbr);
		printf(" : %i\n", nbr);
		ft_printf("Unsign\t%u", ((unsigned int)nbr));
		printf(" : %u\n", ((unsigned int)nbr));
		ft_printf("Hex x:%x\t X: %X\n", nbr, nbr);
		printf("Real: %x\t X: %X\n", nbr, nbr);
		ft_printf("%%\t%%");
		printf(" : %%\n\n");
	}
}
