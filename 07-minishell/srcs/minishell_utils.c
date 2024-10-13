/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbandara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:17:29 by cbandara          #+#    #+#             */
/*   Updated: 2024/09/27 17:14:34 by cbandara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*skip_spaces(const char *c, int *space_count)
{
	*space_count = 0;
	while (*c == ' ' && *c != '\0')
	{
		c++;
		(*space_count)++;
	}
	return (c);
}

int	handle_redirect_error(char redirect_type)
{
	if (redirect_type == '>')
		errmsg("minihell", NULL, 6);
	else if (redirect_type == '<')
		errmsg("minihell", NULL, 7);
	return (1);
}

int	checkdouble_redirect(const char *line)
{
	const char	*c;
	int			i;
	int			redirect_type;

	i = 0;
	c = line;
	while (*c)
	{
		i = 0;
		if (!checkquotes(line, c) && (*c == '>' || *c == '<'))
		{
			redirect_type = *c;
			c++;
			c = skip_spaces(c, &i);
			if (*c == '\0')
				break ;
			if (*c == redirect_type && i)
				return (handle_redirect_error(redirect_type));
		}
		c++;
	}
	return (0);
}

int	check_three_consecutive(char c, int *count, char redirect_char)
{
	if (c == redirect_char)
	{
		(*count)++;
		if (*count == 3)
			return (errmsg("minihell", NULL, 5), 1);
	}
	else
		*count = 0;
	return (0);
}

int	checkthreesome(const char *line)
{
	const char	*c;
	int			i;
	int			j;

	c = line;
	i = 0;
	j = 0;
	while (*c)
	{
		if (!checkquotes(line, c) && *c == ' ')
		{
			c++;
			continue ;
		}
		if (!checkquotes(line, c))
		{
			if (check_three_consecutive(*c, &i, '<'))
				return (1);
			if (check_three_consecutive(*c, &j, '>'))
				return (1);
		}
		c++;
	}
	return (0);
}

/*
static int	checkdouble_redirect(const char *line)
{
	const char	*c;
	int			i;
	int			redirect_type;

	i = 0;
	c = line;
	while (*c)
	{
		i = 0;
		if (!checkquotes(line, c) && (*c == '>' || *c == '<'))
		{
			redirect_type = *c;
			c++;
			while (*c == ' ' && *c != '\0')
			{
				c++;
				i++;
			}
			if (*c == '\0')
				break ;
			if (*c == redirect_type && i)
			{
				if (redirect_type == '>')
					errmsg("minihell", NULL, 6);
				else if (redirect_type == '<')
					errmsg("minihell", NULL, 7);
				return (1);
			}
		}
		c++;
	}
	return (0);
}

static int	checkthreesome(const char *line)
{
	const char	*c;
	int			i;
	int			j;

	c = line;
	i = 0;
	j = 0;
	while (*c)
	{
		if (!checkquotes(line, c) && *c == ' ')
		{
			c++;
			continue ;
		}
		if (!checkquotes(line, c) && *c == '<')
		{
			i++;
			if (i == 3)
				return (errmsg("minihell", NULL, 5), 1);
		}
		else
			i = 0;
		if (!checkquotes(line, c) && *c == '>')
		{
			j++;
			if (j == 3)
				return (errmsg("minihell", NULL, 5), 1);
		}
		else
			j = 0;
		c++;
	}
	return (0);
}
*/
