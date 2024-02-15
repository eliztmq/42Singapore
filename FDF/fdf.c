/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:13 by eteo              #+#    #+#             */
/*   Updated: 2024/02/15 23:07:52 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

int	key_exit(int keycode, t_visual *visual)
{
	if (keycode == XK_Escape)
		close_win(visual);
	return (0);
}

int	close_win(t_visual *visual)
{
	mlx_destroy_window(visual->vars.mlx, visual->vars.win);
}

void	error_msg(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_visual	visual;
	t_grid		grid;
	t_coord		**all_points;
	int			fd;

	if (argc != 2)
		error_msg("Incorrect inputs\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg("File Access\n");
	all_points = (t_coord **)malloc(sizeof(t_coord));
	if (!all_points)
		error_msg("Malloc Error\n");
	create_window(&visual);
	create_grid(fd, &grid, all_points);
	mlx_hook(visual.vars.win, KEY_PRESS, 1L << 0, key_exit, &visual);
	mlx_hook(visual.vars.win, MOUSE_DOWN, 1L << 2, mouse_down, &visual);
	mlx_hook(visual.vars.win, MOUSE_MOVE, 1L << 3, mouse_up, &visual);
	mlx_hook(visual.vars.win, MOUSE_UP, 1L << 6, mouse_drag, &visual);
	mlx_hook(visual.vars.win, EXIT, 1L << 17, close_win, &visual);
	mlx_loop(visual.vars.mlx);
}
