/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/05/07 13:29:55 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_mlx	*fdf;

	fdf = NULL;
	if (ac == 2 && !ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4))
	{
		fdf = initmlx(fdf, av[1]);
		if (!fdf)
			return (1);
		if (intinput(av[1], fdf) == -1)
			return (ft_freeint(fdf->map), free(fdf), 1);
	}
	else
		return (ft_putstr_fd("Invalid arguments or map(s)\n", 2), 0);
	fdfvalues(fdf);
	drawstuff(fdf);
	mlx_put_image_to_window (fdf->ptr, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_hook(fdf->win, 17, 0L, &xbutton, fdf);
	mlx_loop(fdf->ptr);
	return (0);
}
