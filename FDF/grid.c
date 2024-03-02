/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:44:48 by elizabethte       #+#    #+#             */
/*   Updated: 2024/03/02 16:20:07 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

int	count_outer_list(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	fill_points(char *read_str, t_grid *grid)
{
	char	**row_coord;
	t_coord	temp_point;
	int		i;
	int		total_pts;

	i = -1;
	grid->all_points = ft_realloc(grid->all_points, (grid->max_y + 2)
			* sizeof(t_coord *), (grid->max_y + 1) * sizeof(t_coord *));
	row_coord = ft_split(read_str, ' ');
	free(read_str);
	total_pts = count_outer_list(row_coord);
	grid->all_points[grid->max_y] = ft_calloc(total_pts, sizeof(t_coord));
	while (++i < count_outer_list(row_coord))
	{
		temp_point.x = i  * 2;
		temp_point.y = grid->max_y  * 2;
		temp_point.z = ft_atoi(&row_coord[i][0])  * 2;
		grid->all_points[grid->max_y][i] = temp_point;
	}
	grid->max_x = i;
	ft_free(row_coord);
}

void	create_grid(int fd, t_grid *grid)
{
	char	*read_str;
	t_coord	**all_points;

	all_points = (t_coord **)malloc(sizeof(t_coord *));
	if (!all_points)
		error_msg("Malloc Error\n");
	grid->all_points = all_points;
	grid->max_x = 0;
	grid->max_y = 0;
	while ((read_str = get_next_line(fd)) != NULL )
	{
		fill_points(read_str, grid);
		grid->max_y++;
	}
}
