/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:13 by eteo              #+#    #+#             */
/*   Updated: 2024/03/05 15:05:44 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

int	key_exit(int keycode, t_visual *vis)
{
	if (keycode == XK_Escape)
		close_win(vis);
	return (0);
}

int	close_win(t_visual *vis)
{
	int	i;

	i = -1;
	mlx_destroy_image(vis->vars.mlx, vis->img.img);
	mlx_destroy_window(vis->vars.mlx, vis->vars.win);
	mlx_destroy_display(vis->vars.mlx);
	while (++i < vis->grid->max_y)
		free(vis->grid->all_points[i]);
	free(vis->grid->all_points);
	free(vis->grid);
	free(vis->vars.mlx);
	exit(0);
}

void	error_msg(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_visual	vis;
	t_grid		*grid;
	int			fd;

	if (argc != 2)
		error_msg("Incorrect inputs\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg("File Access\n");
	grid = (t_grid *)malloc(sizeof(t_grid));
	if (!grid)
		error_msg("Malloc Error\n");
	create_grid(fd, grid);
	create_window(&vis, grid);
	render_grid(&vis);
	mlx_hook(vis.vars.win, KEY_PRESS, 1L << 0, key_exit, &vis);
	mlx_hook(vis.vars.win, MOUSE_DOWN, 1L << 2, mouse_down, &vis);
	mlx_hook(vis.vars.win, MOUSE_UP, 1L << 3, mouse_up, &vis);
	mlx_hook(vis.vars.win, MOUSE_MOVE, 1L << 6, mouse_drag, &vis);
	mlx_hook(vis.vars.win, EXIT, 1L << 17, close_win, &vis);
	mlx_loop_hook(vis.vars.mlx, render_grid, &vis);
	mlx_loop(vis.vars.mlx);
}
