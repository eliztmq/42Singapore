/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:15:20 by elizabethte       #+#    #+#             */
/*   Updated: 2024/03/11 15:31:52 by eteo             ###   ########.fr       */
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

# define M_PI 3.14159265358979323846

# define MOUSE_CLICK_RIGHT 3
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_DOWN 4
# define MOUSE_UP 5
# define MOUSE_MOVE 6
# define EXIT 17

# define WIN_WIDTH 920
# define WIN_HEIGHT 480

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

typedef	struct line_data
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

typedef struct euler_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

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

typedef struct grid_data
{
	t_coord	**all_points;
	int		max_x;
	int		max_y;
}	t_grid;

typedef struct s_visual
{
	t_data	img;
	t_vars	vars;
	t_mouse	mouse;
	int		centre_x;
	int		centre_y;
	t_grid	*grid;
}	t_visual;

typedef struct quat_rot
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quat;

//fdf.c
int		key_exit(int keycode, t_visual *vis);
int		close_win(t_visual *vis);
void	error_msg(char *str);

//grid.c
int		count_outer_list(char **str);
void	ft_free(char **str);
void	fill_points(char *read_str, t_grid *grid);
void	create_grid(int fd, t_grid *grid);

//line.c
t_coord	trans_pt(t_coord p, t_visual *vis);
void	fill_line(t_line *line, t_coord p0, t_coord p1);
void	drawline(t_data *img, t_coord p0, t_coord p1);
void	NewFunction(int swap, t_data *img, int y, int x);
void	drawing_logic(t_visual *vis);

// mouse.c
int		mouse_down(int button, int x, int y, t_visual *vis);
int		mouse_drag(int x, int y, t_visual *vis);
int		mouse_up(int button, int x, int y, t_visual *vis);

//rotate.c
void	rotate_grid(t_visual *vis);
t_coord	rotate_point(t_coord *pt, t_quat q);

//window.c
void	my_mlx_pixel_put(t_data	*data, int x, int y, int color);
void	black_canvas(t_visual *vis);
int		render_grid(t_visual *vis);
void	initial_val(t_visual *vis, t_grid *grid);
void	create_window(t_visual *vis, t_grid *grid);
#endif
