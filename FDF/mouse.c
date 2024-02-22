/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:56:39 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/22 22:33:33 by elizabethte      ###   ########.fr       */
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
	vis->mouse.x = x;
	vis->mouse.y = y;
	//draw with change in angle
	return (0);
}

int	mouse_up(int button, int x, int y, t_visual *vis)
{
	if (button != MOUSE_CLICK_RIGHT)
		return (1);
	vis->mouse.button = 0;
	return (0);
}
