/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:25:19 by eteo              #+#    #+#             */
/*   Updated: 2024/03/04 21:47:42 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

t_coord	trans_pt(t_coord p, t_visual *vis)
{
	t_coord	new_pt;

	new_pt.x = (p.x + vis->centre_x);
	new_pt.y = (p.y + vis->centre_y);
	new_pt.z = p.z;
	return (new_pt);
}

int	swapx_y(t_coord *p0, t_coord *p1)
{
	int	s_x;
	int	s_y;

	if ((p1->y - p0->y) > (p1->x - p0->x))
	{
		s_x = p0->x;
		p0->x = p0->y;
		p0->y = s_x;
		s_y = p1->y;
		p1->y = p1->x;
		p1->x = s_y;
		return (1);
	}
	else
		return (0);
}

void	drawline(t_data *img, t_coord p0, t_coord p1)
{
	int	swap;
	int	x;
	int	y;
	int	p;

	swap = swapx_y(&p0, &p1);
	x = p0.x;
	y = p0.y;
	p = (2 * (p1.y - p0.y)) - (p1.x - p0.x);
	while (x <= p1.x)
	{
		if (swap == 1)
			my_mlx_pixel_put(img, y, x, 255);
		else if (swap == 0)
			my_mlx_pixel_put(img, x, y, 255);
		x++;
		if (p < 0)
			p = p + (2 * (p1.y - p0.y));
		else
		{
			p = p + (2 * (p1.y - p0.y)) - (2 * (p1.x - p0.x));
			y++;
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
