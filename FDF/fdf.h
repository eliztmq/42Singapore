/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:15:20 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/27 22:57:43 by elizabethte      ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

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
	int		button;
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;
	double	rot_angle;
	t_coord	rot_axis;
}	t_mouse;

typedef struct s_visual
{
	t_data	img;
	t_vars	vars;
	t_mouse	mouse;
	int		centre_x;
	int		centre_y;
	t_grid	*grid;
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

//to be updated
int		key_hook(int keycode, t_visual *vis);
int		mouse_hook(int x, int y);
void	my_mlx_pixel_put(t_data	*data, int x, int y, int color);

int		swapx_y(t_coord *p0, t_coord *p1);
void	drawline(t_data *img, t_coord p0, t_coord p1);

#endif
