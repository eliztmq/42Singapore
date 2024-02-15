/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:44:48 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/15 23:10:02 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

int	count_outer_list(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	fill_points(char *read_str, t_grid *grid)
{
	char	**row_coord;
	t_coord	temp_point;
	int		i;

	i = -1;
	row_coord = ft_split(read_str, ' ');
	while (++i < count_outer_list(row_coord))
	{
		temp_point.x = i;
		temp_point.y = grid->max_y;
		temp_point.z = ft_atoi(&row_coord[i][0]);
		grid->all_points[grid->max_y][i] = temp_point;
	}
	grid->max_x = i;
}

void	create_grid(int fd, t_grid *grid, t_coord **all_points)
{
	char	*read_str;

	grid->all_points = all_points;
	grid->max_x = 0;
	grid->max_y = 0;
	read_str = get_next_line(fd);
	while (read_str != NULL)
	{
		fill_points(read_str, grid);
		grid->max_y++;
		read_str = get_next_line(fd);
	}
}
