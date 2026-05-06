/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_ctl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:45:45 by driemers          #+#    #+#             */
/*   Updated: 2025/04/15 13:08:54 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "minirt.h"
#include "stdlib.h"

// this file is copied from my own (driemers) fract-ol project.

void	put_pixel(t_img *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

// unsigned int	get_pixel(t_img *data, int x, int y)
// {
// 	char			*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	return (*(unsigned int *)dst);
// }

void	init_frame(t_win *win)
{
	win->img.img = mlx_new_image(win->mlx, win->res_x, win->res_y);
	if (win->img.img != NULL)
		win->img.addr = mlx_get_data_addr(win->img.img,
				&win->img.bits_per_pixel,
				&win->img.line_length, &win->img.endian);
}

// void	clear_frame(t_win *win)
// {
// 	int	index_x;
// 	int	index_y;

// 	index_x = 0;
// 	while (index_x < win->res_x)
// 	{
// 		index_y = 0;
// 		while (index_y < win->res_y)
// 		{
// 			index_y++;
// 			put_pixel(&win->img, index_x, index_y, 0);
// 		}
// 		index_x++;
// 	}
// }

void	push_frame(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
}
