/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:25:19 by eteo              #+#    #+#             */
/*   Updated: 2024/02/15 23:10:36 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	swapx_y(int *x0, int *y0, int *x1, int *y1)
{
	int	s_x;
	int	s_y;

	if ((*y1 - *y0) / (*x1 - *x0))
	{
		s_x = *x0;
		*x0 = *y0;
		*y0 = s_x;
		s_y = *y1;
		*y1 = *x1;
		*x1 = s_y;
		return (1);
	}
	else
		return (0);
}

void	drawline(t_data img, int x0, int y0, int x1, int y1)
{
	int	swap;
	int	x;
	int	y;
	int	p;

	swap = swapx_y(&x0, &y0, &x1, &y1);
	x = x0;
	y = y0;
	p = (2 * (y1 - y0)) - (x1 - x0);
	while (x <= x1)
	{
		if (swap == 1)
			my_mlx_pixel_put(&img, y, x, 255);
		else if (swap == 0)
			my_mlx_pixel_put(&img, x, y, 255);
		x++;
		if (p < 0)
			p = p + (2 * (y1 - y0));
		else
		{
			p = p + (2 * (y1 - y0)) - (2 * (x1 - x0));
			y++;
		}
	}
}
