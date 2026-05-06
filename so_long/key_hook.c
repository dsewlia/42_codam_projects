/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:04 by dsewlia           #+#    #+#             */
/*   Updated: 2025/02/21 12:44:35 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *map_data)
{
	if (map_data->map[map_data->images[ENTRY]->instances->y / TLE - 1]
		[map_data->images[ENTRY]->instances->x / TLE] != '1')
	{
		map_data->images[ENTRY]->instances->y -= TLE;
		map_data->move_count++;
		ft_printf("MOVES: %d\n", map_data->move_count);
	}
}

void	move_down(t_data *map_data)
{
	if (map_data->map[map_data->images[ENTRY]->instances->y / TLE + 1]
		[map_data->images[ENTRY]->instances->x / TLE] != '1')
	{
		map_data->images[ENTRY]->instances->y += TLE;
		map_data->move_count++;
		ft_printf("MOVES: %d\n", map_data->move_count);
	}
}

void	move_left(t_data *map_data)
{
	if (map_data->map[map_data->images[ENTRY]->instances->y / TLE]
		[map_data->images[ENTRY]->instances->x / TLE - 1] != '1')
	{
		map_data->images[ENTRY]->instances->x -= TLE;
		map_data->move_count++;
		ft_printf("MOVES: %d\n", map_data->move_count);
	}
}

void	move_right(t_data *map_data)
{
	if (map_data->map[map_data->images[ENTRY]->instances->y / TLE]
		[map_data->images[ENTRY]->instances->x / TLE + 1] != '1')
	{
		map_data->images[ENTRY]->instances->x += TLE;
		map_data->move_count++;
		ft_printf("MOVES: %d\n", map_data->move_count);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *ptr)
{
	t_data	*map_data;

	map_data = ptr;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_RELEASE)
		move_up(map_data);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_RELEASE)
		move_down(map_data);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
		move_left(map_data);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
		move_right(map_data);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_close_window(map_data->mlx_ptr);
	}
	check_collect(map_data);
}
