/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:03:28 by cwan              #+#    #+#             */
/*   Updated: 2023/11/16 11:53:20 by cwan             ###   ########.fr       */
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
	printf("%s\n", (ft_strcpy(s1, "test")));
	printf("%s\n", (ft_strcpy(s1, "testing \t\t\t\t\t\t\t\ttest")));
	printf("%s\n", (ft_strcpy(s1, "longtest 2234osifsj \n \t \r test")));
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
