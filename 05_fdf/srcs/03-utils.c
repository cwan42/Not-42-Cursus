/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03-utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:43:13 by cwan              #+#    #+#             */
/*   Updated: 2024/05/07 13:27:09 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	xbutton(t_mlx *fdf)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)fdf;
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	ft_freeint(mlx->map);
	free(mlx);
	exit(0);
}

int	keyinput(int button, void *fdf)
{
	t_mlx	*mlx;

	if (button == XK_Escape || button == 0)
	{
		mlx = (t_mlx *)fdf;
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		ft_freeint(mlx->map);
		free(mlx);
		exit(0);
	}
	return (0);
}

void	ft_freeint(int **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}
