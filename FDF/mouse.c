/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:56:39 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/15 23:09:13 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

int	mouse_down(int button, int x, int y, t_visual *visual)
{
	if (button != MOUSE_CLICK_RIGHT)
		return (1);
	visual->mouse.button = 1;
	visual->mouse.x = x;
	visual->mouse.y = y;
	return (0);
}

int	mouse_drag(int x, int y, t_visual *visual)
{
	if (visual->mouse.button != 1)
		return (1);
	visual->mouse.delta_x = x - visual->mouse.x;
	visual->mouse.delta_y = y - visual->mouse.y;
	visual->mouse.x = x;
	visual->mouse.y = y;
	return (0);
}

int	mouse_up(int button, int x, int y, t_visual *visual)
{
	if (button != MOUSE_CLICK_RIGHT)
		return (1);
	visual->mouse.button = 0;
	return (0);
}
