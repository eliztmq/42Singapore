/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:19:19 by elizabethte       #+#    #+#             */
/*   Updated: 2024/03/07 14:38:15 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	black_canvas(t_visual *vis)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		j = -1;
		while (++j < WIN_HEIGHT)
			my_mlx_pixel_put(&vis->img, i, j, 0);
	}
	mlx_put_image_to_window(vis->vars.mlx, vis->vars.win, vis->img.img, 0, 0);
}

int	render_grid(t_visual *vis)
{
	black_canvas(vis);
	rotate_grid(vis);
	drawing_logic(vis);
	mlx_put_image_to_window(vis->vars.mlx, vis->vars.win, vis->img.img, 0, 0);
	return (0);
}

void	initial_val(t_visual *vis, t_grid *grid)
{
	t_mouse	mouse;
	t_coord	rot_axis;

	mouse.rot_angle = 25 * M_PI / 180;
	mouse.button = 0;
	mouse.x = 0;
	mouse.y = 0;
	mouse.delta_x = 0;
	mouse.delta_y = 0;
	rot_axis.x = 1;
	rot_axis.y = 1;
	rot_axis.z = 0;
	mouse.rot_axis = rot_axis;
	vis->mouse = mouse;
	vis->centre_x = (WIN_WIDTH - grid->max_x) / 2;
	vis->centre_y = (WIN_HEIGHT - grid->max_y) / 2;
	vis->grid = grid;
}

void	create_window(t_visual *vis, t_grid *grid)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	vis->img = img;
	vis->vars = vars;
	initial_val(vis, grid);
}
