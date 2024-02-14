/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:13 by eteo              #+#    #+#             */
/*   Updated: 2024/02/14 18:43:59 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	if (keycode == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(int x, int y)
{
	printf("X: %i, Y: %i\n", x, y);
	return (0);
}

void	error_msg(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	if (argc != 2)
		error_msg("Incorrect inputs");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg("File Access");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "fdf");
	create_image(&vars);
	create_grid(fd);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 6, 1L<<6, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}

