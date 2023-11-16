/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:41:34 by cwan              #+#    #+#             */
/*   Updated: 2023/11/16 11:52:27 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(void)
{
	ft_putstr("test string 123 \t \n \n \r\r\r\t\t\%%%");
}

/*
Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that displays a string on the standard output.
The pointer passed to the function contains the address of the string's first
character.
Your function must be declared as follows:
void	ft_putstr(char *str);
*/
