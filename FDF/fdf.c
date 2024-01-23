/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:13 by eteo              #+#    #+#             */
/*   Updated: 2024/01/23 15:11:30 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	if (keycode == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(int x, int y)
{
	printf("X: %i, Y: %i\n", x, y);
	return (0);
}

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	// int		i;
	t_data	img;
	t_vars	vars;

	// i = -1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "Hello world!!!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	drawline(img, 50, 50, 300, 100);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 6, 1L<<6, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

