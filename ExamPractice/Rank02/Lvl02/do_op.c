/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:30:25 by cwan              #+#    #+#             */
/*   Updated: 2024/01/08 17:25:03 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char *av[])
{
	char	operand;
	
	operand = av[2][0];
	if (ac == 4)
	{
		if (operand == '+')
			printf("%d", atoi(av[1]) + atoi(av[3]));
		else if (operand == '-')
			printf("%d", atoi(av[1]) - atoi(av[3]));
		else if (operand == '*')
			printf("%d", atoi(av[1]) * atoi(av[3]));
		else if (operand == '/')
			printf("%d", atoi(av[1]) / atoi(av[3]));
		else if (operand == '%')
			printf("%d", atoi(av[1]) % atoi(av[3]));
	}
	printf("\n");
	return (0);
}

// cannot use * without "*" because interpreted as wildcard
// use printf for \n instead of write because printf flushes buffer, otherwise write creates extra newline before answer.
/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------
Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %
The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.
You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.
Examples:
$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/
