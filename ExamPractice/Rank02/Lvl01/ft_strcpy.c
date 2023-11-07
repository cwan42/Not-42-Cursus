/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:03:28 by cwan              #+#    #+#             */
/*   Updated: 2023/10/20 15:07:56 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
		s1[i] = s2[i++];
	s1[++i] = '\0';
	return (s1);
}

#include <stdio.h>

int	main(void)
{
	char s1[100];
	printf("%s\n", (ft_strcpy(s1, "fuck")));
	printf("%s\n", (ft_strcpy(s1, "fuckety \t\t\t\t\t\t\t\tfuck fuck")));
	printf("%s\n", (ft_strcpy(s1, "fuckening fuckering fuck 123 \n \t \r fuck")));
}

/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------
Reproduce the behavior of the function strcpy (man strcpy).
Your function must be declared as follows:
char    *ft_strcpy(char *s1, char *s2);
*/
