/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:24:54 by elizabethte       #+#    #+#             */
/*   Updated: 2024/03/15 06:18:32 by eteo             ###   ########.fr       */
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

	rot_transf = mquat(axis_quat(vis->mouse.rot_anglex, 1, 0 , 0), axis_quat(vis->mouse.rot_angley, 0 , 1, 0));
	rotated_pts = malloc(sizeof(t_coord *) * vis->grid->max_y);
	j = -1;
	while (++j < vis->grid->max_y)
	{
		i = -1;
		rotated_pts[j] = ft_calloc(vis->grid->max_x, sizeof(t_coord));
		while (++i < vis->grid->max_x)
		{
			rotated_pts[j][i] = trans_points(vis->grid->all_points[j][i], vis);
			rotated_pts[j][i] = rotate_point(&rotated_pts[j][i], rot_transf);
		}
	}
	return(rotated_pts);
}

t_quat	axis_quat(double angle, int x, int y, int z)
{
	t_quat	output_axis;

	output_axis.w = cos(angle / 2);
	output_axis.x = sin(angle / 2) * x;
	output_axis.y = sin(angle / 2) * y;
	output_axis.z = sin(angle / 2) * z;
	return(output_axis);
}

t_quat	mquat(t_quat q1, t_quat q2)
{
	t_quat q_r;
	
	q_r.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	q_r.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	q_r.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	q_r.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (q_r);
}

t_coord	trans_points(t_coord pt, t_visual *vis)
{
	t_coord	trans_pt;

	trans_pt.x = (pt.x * vis->scale) + (vis->grid->max_x * vis->scale / 2);
	trans_pt.y = (pt.y * vis->scale) + (vis->grid->max_y * vis->scale / 2);
	trans_pt.z = (pt.z * vis->scale);
	return(trans_pt);
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
