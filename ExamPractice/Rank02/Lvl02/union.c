/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:00:28 by cwan              #+#    #+#             */
/*   Updated: 2024/01/30 13:40:13 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isfirst(char *str, char c, int pos)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i == pos);
}

int	main(int ac, char *av[])
{
	int	i = 0;
	int	j = 0;
	char 	*str;

	if (ac != 3)
		return (write(1, "\n", 1), 0);
	str = av[1];
	while (str[i])
		i++;
	while (av[2][j])
	{
		str[i] = av[2][j];
		i++;
		j++;
	}
	str[i] = '\0';
	i = 0;
	while (str[i])
	{
		if (isfirst(str, str[i], i))
			write(1, &str[i], 1);
		i++;
	}
	return (write(1, "\n", 1), 0);
}

/* Solulu 02
#include <unistd.h>

int	ft_isfirst(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i == pos);
}

char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (str2[j])
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	return (str1);
}

int	main(int ac, char *av[])
{
	char *str;
	int		i;
	
	if (ac != 3)
		return (write(1, "\n", 1), 0);
	str = ft_strcat(av[1], av[2]);
	i = 0;
	while (str[i])
	{
		if (ft_isfirst(str, str[i], i))
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}*/

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$> */
