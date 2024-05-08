/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-mlxutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:21:11 by cwan              #+#    #+#             */
/*   Updated: 2024/05/07 12:37:49 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	pixelstodraw(t_mlx *fdf)
{
	int	pixels;

	pixels = sqrt((fdf->xd * fdf->xd) + (fdf->yd * fdf->yd));
	fdf->xd /= pixels;
	fdf->yd /= pixels;
	return (pixels);
}

static void	drawline(t_mlx *fdf, int beginX, int beginY)
{
	double	pixelx;
	double	pixely;
	int		x;
	int		y;
	int		index;

	pixelx = beginX;
	pixely = beginY;
	while (fdf->pixels)
	{
		x = (int)pixelx;
		y = (int)pixely;
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		{
			index = (y * fdf->size_line) + (x * (fdf->bpp / 8));
			*(unsigned int *)(fdf->data + index) = 0x00FFFFFF;
		}
		pixelx += fdf->xd;
		pixely += fdf->yd;
		--fdf->pixels;
	}
}

static void	setxy(t_mlx *fdf, int x, int y)
{
	int	z;

	z = fdf->map[y][x];
	fdf->xrot = x * cos(fdf->theta) - y * sin(fdf->theta) * 0.7;
	fdf->yrot = x * sin(fdf->theta) + y * cos(fdf->theta) * 0.7 - (z * 0.2);
}

static void	setxyn(t_mlx *fdf, int x, int y)
{
	int	z;

	z = fdf->map[y][x];
	fdf->xrotn = x * cos(fdf->theta) - y * sin(fdf->theta) * 0.7;
	fdf->yrotn = x * sin(fdf->theta) + y * cos(fdf->theta) * 0.7 - (z * 0.2);
	fdf->xd = (fdf->xrotn * fdf->scale + 300) - (fdf->xrot * fdf->scale + 300);
	fdf->yd = (fdf->yrotn * fdf->scale + 100) - (fdf->yrot * fdf->scale + 100);
	fdf->pixels = pixelstodraw(fdf);
	drawline(fdf, fdf->xrot * fdf->scale + 300, fdf->yrot * fdf->scale + 100);
}

void	drawstuff(t_mlx *fdf)
{
	int		x;
	int		y;

	fdf->data = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->size_line, \
	&fdf->endian);
	if (!fdf->data)
	{
		ft_putstr_fd("Fdf data addr failed\n", 2);
		return ;
	}
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			setxy(fdf, x, y);
			if (x + 1 < fdf->cols)
				setxyn(fdf, x + 1, y);
			if (y + 1 < fdf->rows)
				setxyn(fdf, x, y + 1);
			x++;
		}
		y++;
	}
}
