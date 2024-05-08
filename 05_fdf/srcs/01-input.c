/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:58:27 by cwan              #+#    #+#             */
/*   Updated: 2024/05/07 13:03:21 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdfvalues(t_mlx *fdf)
{
	fdf->theta = 30 * M_PI / 180;
	if (fdf->rows < fdf->cols)
		fdf->scale = ((double)HEIGHT / fdf->rows) / 2;
	else
		fdf->scale = ((double)WIDTH / fdf->cols) / 2;
}

static int	numcol(t_mlx *fdf, char *av)
{
	int		fd;
	int		x;
	int		xcheck;
	char	*line;
	char	**splitline;

	fd = open(av, O_RDONLY);
	xcheck = 0;
	x = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (xcheck != x)
			return (close(fd), -1);
		x = 0;
		splitline = ft_split(line, ' ');
		while (splitline[x])
			x++;
		xcheck = x;
		ft_free(splitline);
		free(line);
		line = get_next_line(fd);
	}
	fdf->cols = x;
	return (close(fd), 0);
}

static int	numrow(t_mlx *fdf, char *av)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	fdf->rows = y;
	y = numcol(fdf, av);
	return (y);
}

int	intinput(char *av, t_mlx *fdf)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**splitline;

	i = 0;
	fd = open(av, O_RDONLY);
	fdf->map = malloc(sizeof(int *) * (fdf->rows + 1));
	if (!fdf->map)
		return (close(fd), ft_putstr_fd("Fdf malloc failed", 2), -1);
	line = get_next_line(fd);
	while (line)
	{
		j = -1;
		splitline = ft_split(line, ' ');
		fdf->map[i] = malloc(sizeof(int) * (fdf->cols));
		while (splitline[++j])
			fdf->map[i][j] = ft_atoi(splitline[j]);
		(void)(free(line), ft_free(splitline));
		line = get_next_line(fd);
		i++;
	}
	fdf->map[i] = NULL;
	return (close(fd), 0);
}

t_mlx	*initmlx(t_mlx *fdf, char *av)
{
	char	*title;

	fdf = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!fdf)
		return (ft_putstr_fd("Fdf malloc failed\n", 2), NULL);
	if (numrow(fdf, av) == -1)
		return (free(fdf), ft_putstr_fd("Map invalid or failed\n", 2), NULL);
	fdf->ptr = mlx_init();
	if (!fdf->ptr)
		return (free(fdf), ft_putstr_fd("Fdf mlx_init failed", 2), NULL);
	title = ft_strjoin("FdF: ", av);
	fdf->win = mlx_new_window(fdf->ptr, WIDTH, HEIGHT, title);
	free(title);
	if (!fdf->win)
		return (ft_putstr_fd("Fdf init window failed", 2), NULL);
	fdf->img = mlx_new_image(fdf->ptr, WIDTH, HEIGHT);
	if (!fdf->img)
		return (ft_putstr_fd("Fdf init image failed", 2), NULL);
	return (fdf);
}
