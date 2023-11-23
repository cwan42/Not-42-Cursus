/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILTESTmain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan42 <cwan42@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:14:24 by cwan42            #+#    #+#             */
/*   Updated: 2023/11/21 13:10:42 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	word[200];
	char	*strcpyword;
	void	*array;

	scanf("%199s", word);
	printf("strlen: %s is %lu bytes.\n", word, ft_strlen(word));
	printf("strchr: %s has X in it.\n", ft_strchr(word, 'X'));
	printf("strjoin: %s\n", ft_strjoin("Nama saya ", word));
	strcpyword = ft_strdup(word);
	printf("strdup: %s\n", strcpyword);
	array = ft_calloc(ft_strlen(word), sizeof(char));
	if (array)
	{
		printf("calloc: allocated %lu bytes\n", ft_strlen(array));
		free(array);
	}
	else
		printf("Calloc failed\n");
}
