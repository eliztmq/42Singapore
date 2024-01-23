/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:15:20 by elizabethte       #+#    #+#             */
/*   Updated: 2024/01/23 15:09:00 by eteo             ###   ########.fr       */
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

int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int x, int y);
void	my_mlx_pixel_put(t_data	*data, int x, int y, int color);

int swapx_y(int *x0, int *y0, int *x1, int *y1);
void drawline(t_data img, int x0, int y0, int x1, int y1);

#endif
