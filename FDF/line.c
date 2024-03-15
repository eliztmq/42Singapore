/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:25:19 by eteo              #+#    #+#             */
/*   Updated: 2024/03/15 14:37:56 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

t_coord	trans_pt(t_coord p, t_visual *vis)
{
	t_coord	new_pt;

	new_pt.x = p.x - (vis->grid->max_x * vis->scale / 2) + vis->centre_x;
	new_pt.y = p.y - (vis->grid->max_y * vis->scale / 2) + vis->centre_y;
	new_pt.z = p.z;
	return (new_pt);
}

void	fill_line(t_line *line, t_coord p0, t_coord p1)
{
	line->dx = abs(p1.x - p0.x);
	line->dy = -1 * abs(p1.y - p0.y);
	if (p0.x < p1.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (p0.y < p1.y)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx + line->dy;
}

void	drawline(t_data *img, t_coord p0, t_coord p1)
{
	t_line	line;

	fill_line(&line, p0, p1);
	while (1)
	{
		my_mlx_pixel_put(img, p0.x, p0.y, 255);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			line.err += line.dy;
			p0.x += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.err += line.dx;
			p0.y += line.sy;
		}
	}
}

void	drawing_logic(t_visual *vis)
{
	int	i;
	int	j;

	j = 0;
	while (j < vis->grid->max_y)
	{
		i = 0;
		while (i < vis->grid->max_x)
		{
			if (i != vis->grid->max_x - 1)
				drawline(&vis->img, trans_pt(vis->grid->all_points[j][i], vis),
					trans_pt(vis->grid->all_points[j][i + 1], vis));
			if (j != 0)
				drawline(&vis->img, trans_pt(vis->grid->all_points[j][i], vis),
					trans_pt(vis->grid->all_points[j - 1][i], vis));
			i++;
		}
		j++;
	}
}
