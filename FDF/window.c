/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:19:19 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/22 22:58:38 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

void	render_grid(t_visual *vis, t_grid *grid)
{
	create_window(vis, grid);
	rotate_grid(vis, grid);
	//project
	drawline(vis->img, 50, 50, 300, 100);
	mlx_put_image_to_window(vis->vars.mlx, vis->vars.win, vis->img.img, 0, 0);
}

void	create_window(t_visual *vis, t_grid *grid)
{
	t_data	img;
	t_vars	vars;
	t_mouse	mouse;
	t_coord	rot_axis;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mouse.rot_angle = 45 * 180 / M_PI;
	mouse.button = 0;
	mouse.x = 0;
	mouse.y = 0;
	mouse.delta_x = 0;
	mouse.delta_y = 0;
	rot_axis.x = 1;
	rot_axis.y = 1;
	rot_axis.z = 0;
	mouse.rot_axis = rot_axis;
	vis->img = img;
	vis->vars = vars;
	vis->mouse = mouse;
	vis->centre_x = (WIN_WIDTH - grid->max_x) / 2;
	vis->centre_y = (WIN_HEIGHT - grid->max_y) / 2;
}
