/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-strproc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:51:05 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/27 12:51:11 by cbandara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_initial_copy(char **ptr, char **str, char c)
{
	**ptr = **str;
	(*ptr)++;
	(*str)++;
	if (**str == c)
	{
		**ptr = **str;
		(*ptr)++;
		(*str)++;
		if (**str == c)
			return (-1);
	}
	**ptr = ' ';
	(*ptr)++;
	return (0);
}

int	handle_space_and_copy(char **ptr, char **str)
{
	char	*tmp;

	while (**str == ' ')
		(*str)++;
	tmp = *str;
	while (**str && **str != '<' && **str != '>')
	{
		**ptr = **str;
		(*ptr)++;
		(*str)++;
		if (**str == ' ' && !checkquotes(tmp, *str))
			break ;
	}
	**ptr = ' ';
	(*ptr)++;
	return (0);
}

int	copychars(char **ptr, char **str, char c)
{
	if (handle_initial_copy(ptr, str, c) == -1)
		return (-1);
	return (handle_space_and_copy(ptr, str));
}

/*
static int	copychars(char **ptr, char **str, char c)
{
	char	*tmp;

	**ptr = **str;
	(*ptr)++;
	(*str)++;
	if (**str == c)
	{
		**ptr = **str;
		(*ptr)++;
		(*str)++;
		if (**str == c)
			return (-1);
	}
	**ptr = ' ';
	(*ptr)++;
	while (**str == ' ')
		(*str)++;
	tmp = *str;
	while (**str && **str != '<' && **str != '>')
	{
		**ptr = **str;
		(*ptr)++;
		(*str)++;
		if (**str == ' ' && !checkquotes(tmp, *str))
			break ;
	}
	**ptr = ' ';
	(*ptr)++;
	return (0);
}
*/