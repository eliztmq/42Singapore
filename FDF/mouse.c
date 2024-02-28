/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:56:39 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/28 14:45:03 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

int	mouse_down(int button, int x, int y, t_visual *vis)
{
	if (button != MOUSE_CLICK_RIGHT)
		return (1);
	vis->mouse.button = 1;
	vis->mouse.x = x;
	vis->mouse.y = y;
	return (0);
}

int	mouse_drag(int x, int y, t_visual *vis)
{
	if (vis->mouse.button != 1)
		return (1);
	vis->mouse.delta_x = x - vis->mouse.x;
	vis->mouse.delta_y = y - vis->mouse.y;
	vis->mouse.rot_angle = atan2(vis->mouse.delta_y, vis->mouse.delta_x);
	vis->mouse.x = x;
	vis->mouse.y = y;
	return (0);
}

int	mouse_up(int button, int x, int y, t_visual *vis)
{
	(void)x;
	(void)y;
	if (button != MOUSE_CLICK_RIGHT)
		return (1);
	vis->mouse.button = 0;
	return (0);
}
