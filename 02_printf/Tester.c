/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:31:39 by cwan              #+#    #+#             */
/*   Updated: 2023/09/25 01:51:14 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main()
{
	char	*str = "abcdefgHIJKLM12345";
	int		nbr = 123456789;

	ft_printf("%c", 'X');
	printf(" : %c\n", 'X');
	ft_printf("%s", str);
	printf(" : %s\n", str);
	ft_printf("%p", str);
	printf(" : %p\n", str);
	ft_printf("%d", nbr);
	printf(" : %d\n", nbr);
	ft_printf("%i", nbr);
	printf(" : %i\n", nbr);

	printf(" : %u\n", (unsigned int)nbr);

	printf(" : %x\n", nbr);

	printf(" : %X\n", nbr);
	ft_printf("%s", "%%%%");
	printf(" : %%%%\n");
}
