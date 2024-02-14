/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:44:48 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/14 18:55:47 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

void	create_grid(int fd)
{
	char	*read_str;
	int		***coord;
	int		y;

	y = 0;
	read_str = get_next_line(fd);
	if (read_str != NULL)
		

}