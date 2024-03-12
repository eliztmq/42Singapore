/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:24:54 by elizabethte       #+#    #+#             */
/*   Updated: 2024/03/12 15:07:40 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

t_coord	**rotate_grid(t_visual *vis)
{
	t_quat	rot_transf;
	t_coord	**rotated_pts;
	int		i;
	int		j;

	rot_transf.w = cos(vis->mouse.rot_angle / 2);
	rot_transf.x = sin(vis->mouse.rot_angle / 2) * vis->mouse.rot_axis.x;
	rot_transf.y = sin(vis->mouse.rot_angle / 2) * vis->mouse.rot_axis.y;
	rot_transf.z = sin(vis->mouse.rot_angle / 2) * vis->mouse.rot_axis.z;
	rotated_pts = malloc(sizeof(t_coord *) * vis->grid->max_y);
	j = -1;
	while (++j < vis->grid->max_y)
	{
		i = -1;
		rotated_pts[j] = ft_calloc(vis->grid->max_x, sizeof(t_coord));
		while (++i < vis->grid->max_x)
		{
			rotated_pts[j][i] = scale_points(vis->grid->all_points[j][i], vis);
			rotated_pts[j][i] = rotate_point(&rotated_pts[j][i], rot_transf);
		}
	}
	return(rotated_pts);
}

t_coord	scale_points(t_coord pt, t_visual *vis)
{
	t_coord	scaled_pt;

	scaled_pt.x = pt.x * vis->scale;
	scaled_pt.y = pt.y * vis->scale;
	scaled_pt.z = pt.z * vis->scale;
	return(scaled_pt);
}

t_coord	rotate_point(t_coord *pt, t_quat q)
{
	t_coord	rotated_pt;

	rotated_pt.x = (q.w * q.w * pt->x) + (2 * q.y * q.w * pt->z)
		- (2 * q.z * q.w * pt->y) + (q.x * q.x * pt->x)
		+ (2 * q.y * q.x * pt->y) + (2 * q.z * q.x * pt->z)
		- (q.z * q.z * pt->x) - (q.y * q.y * pt->x);
	rotated_pt.y = (2 * q.x * q.y * pt->x) + (q.y * q.y * pt->y)
		+ (2 * q.z * q.y * pt->z) + (2 * q.w * q.z * pt->x)
		- (q.z * q.z * pt->y) + (q.w * q.w * pt->y)
		- (2 * q.x * q.w * pt->z) - (q.x * q.x * pt->y);
	rotated_pt.z = (2 * q.x * q.z * pt->x) + (2 * q.y * q.z * pt->y)
		+ (q.z * q.z * pt->z) - (2 * q.w * q.y * pt->x) - (q.y * q.y * pt->z)
		+ (2 * q.w * q.x * pt->y) - (q.x * q.x * pt->z) + (q.w * q.w * pt->z);
	return(rotated_pt);
}
