/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/03/26 15:16:41 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyinput(int button)
{
	if (button == 65307)
		exit(0);
	ft_printf("The %d key has been pressed\n", button);
	return (0);
}

void	*createwindow(void *mlx_ptr)
{
	void	*window;

	window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "WINDOW");
	if (!window)
		return (mlx_ptr);
	mlx_key_hook(window, keyinput, NULL);
	mlx_loop(mlx_ptr);
	return (window);
}

int	main(int ac, char *av[])
{
	void	*mlx_ptr;

	(void)(*av[0]);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	createwindow(mlx_ptr);
	sleep(2);
	ft_printf("Sleeploopended ac=%dn", ac);
	if (mlx_ptr)
		return (mlx_destroy_display(mlx_ptr), free(mlx_ptr), 0);
	return (0);	
}
