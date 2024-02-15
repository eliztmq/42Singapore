/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:15:20 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/15 23:08:05 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>

# define MOUSE_CLICK_RIGHT 2
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_DOWN 4
# define MOUSE_UP 5
# define MOUSE_MOVE 6
# define EXIT 17

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct mouse_data
{
	int	button;
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
}	t_mouse;

typedef struct s_visual
{
	t_data	img;
	t_vars	vars;
	t_mouse	mouse;
}	t_visual;

typedef struct grid_data
{
	t_coord	**all_points;
	int		max_x;
	int		max_y;
}	t_grid;

typedef struct euler_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct quat_rot
{
	int	w;
	int	x;
	int	y;
	int	z;
}	t_quat;

int		key_hook(int keycode, t_visual *visual);
int		mouse_hook(int x, int y);
void	my_mlx_pixel_put(t_data	*data, int x, int y, int color);

int		swapx_y(int *x0, int *y0, int *x1, int *y1);
void	drawline(t_data img, int x0, int y0, int x1, int y1);

#endif
