/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:43:00 by driemers          #+#    #+#             */
/*   Updated: 2025/04/25 13:43:46 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "minirt.h"
#include "stdlib.h"
#include "stdio.h"

// this file is copied from my own (driemers) fract-ol project and edited.

int	exit_program(t_win *win)
{
	mlx_loop_end(win->mlx);
	return (0);
}

int	loop(t_win *win)
{
	if (render(win) != 0)
		push_frame(win);
	return (0);
}

int	check_esc(int key, t_win *win)
{
	if (key == KEY_ESC)
		exit_program(win);
	return (0);
}

int	free_everything(int progress, t_scene *scene, t_win *win)
{
	if (progress < 3)
		print_err(ERR_MEM_FAIL);
	if (progress >= 3)
		mlx_destroy_image(win->mlx, win->img.img);
	if (progress >= 2)
		mlx_destroy_window(win->mlx, win->win);
	if (progress >= 1)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	if (progress >= 0)
		free_scene(scene);
	return (0);
}

// setup window
int	program_start(unsigned int x, unsigned int y, t_scene *scene)
{
	t_win	win;

	win.res_x = x;
	win.res_y = y;
	win.mlx = mlx_init();
	if (win.mlx == NULL)
		return (free_everything(0, scene, &win));
	win.win = mlx_new_window(win.mlx, win.res_x, win.res_y, "miniRT");
	if (win.win == NULL)
		return (free_everything(1, scene, &win));
	init_frame(&win);
	if (win.img.img == NULL)
		return (free_everything(2, scene, &win));
	win.scene = scene;
	mlx_hook(win.win, WIN_EXIT, 0, exit_program, &win);
	mlx_key_hook(win.win, check_esc, &win);
	mlx_loop_hook(win.mlx, loop, &win);
	mlx_loop(win.mlx);
	return (free_everything(3, scene, &win));
}
