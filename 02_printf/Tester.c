/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:31:39 by cwan              #+#    #+#             */
/*   Updated: 2023/09/21 17:09:08 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main()
{
	char *str = "abcdefgHIJKLM12345";
	int	nbr = 123456789;

	ft_printc('X');
	printf(" : %c\n", 'X');
	ft_prints(str);
	printf(" : %s\n", str);
	ft_printp((unsigned long)str);
	printf(" : %p\n", str);
	ft_printd(nbr);
	printf(" : %d\n", nbr);
	ft_printd(nbr);
	printf(" : %i\n", nbr);

	printf(" : %u\n", (unsigned int)nbr);

	printf(" : %x\n", nbr);

	printf(" : %X\n", nbr);

	printf(" : %%%%\n");
}
