/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:24:48 by cwan              #+#    #+#             */
/*   Updated: 2023/11/23 15:52:14 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*result;

	i = 0;
	while (src[i])
		i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return(result);
}
/*
#include <stdio.h>

int	main(int ac, char *av[])
{
	char	*duplicate;
	char	*ftduplicate;

	if (ac != 2)
		return (0);
	duplicate = strdup(av[1]);
	ftduplicate = ft_strdup(av[1]);
	printf("Real strdup: %s\nft_strdup:   %s\n", duplicate, ftduplicate);
	return (free(duplicate), free(ftduplicate), 0);
}*/

/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Reproduce the behavior of the function strdup (man strdup).
Your function must be declared as follows:
char    *ft_strdup(char *src);

The strdup() function returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string is obtained with malloc(3), and can be freed with free(3).
RETURN VALUE
On success, the strdup() function returns a pointer to the duplicated string.  It returns NULL if insufficient memory was available, with errno set to indicate the cause of the error.
*/
