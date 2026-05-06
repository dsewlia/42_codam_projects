/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:30:37 by dsewlia           #+#    #+#             */
/*   Updated: 2025/03/28 11:22:14 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_images(t_data *map_data)
{
	map_data->textures[FLOOR] = mlx_load_png("./textures/floor.png");
	map_data->textures[WALL] = mlx_load_png("./textures/wall.png");
	map_data->textures[COLLEC] = mlx_load_png("./textures/coll.png");
	map_data->textures[ENTRY] = mlx_load_png("./textures/player.png");
	map_data->textures[EXTS] = mlx_load_png("./textures/door.png");
	if (check_textures(map_data) == 1)
		return (1);
	map_data->images[FLOOR] = mlx_texture_to_image
		(map_data->mlx_ptr, map_data->textures[FLOOR]);
	map_data->images[WALL] = mlx_texture_to_image
		(map_data->mlx_ptr, map_data->textures[WALL]);
	map_data->images[COLLEC] = mlx_texture_to_image
		(map_data->mlx_ptr, map_data->textures[COLLEC]);
	map_data->images[ENTRY] = mlx_texture_to_image
		(map_data->mlx_ptr, map_data->textures[ENTRY]);
	map_data->images[EXTS] = mlx_texture_to_image
		(map_data->mlx_ptr, map_data->textures[EXTS]);
	mlx_delete_texture(map_data->textures[FLOOR]);
	mlx_delete_texture(map_data->textures[WALL]);
	mlx_delete_texture(map_data->textures[COLLEC]);
	mlx_delete_texture(map_data->textures[ENTRY]);
	mlx_delete_texture(map_data->textures[EXTS]);
	if (check_images(map_data) == 1)
		return (1);
	return (0);
}

int	init_map(t_data *map_data, int i, int j, int error_flag)
{
	while (++i < map_data->height)
	{
		j = -1;
		while (++j < map_data->length)
		{
			error_flag = mlx_image_to_window(map_data->mlx_ptr, \
				map_data->images[FLOOR], j * TLE, i * TLE);
			if (map_data->map[i][j] == '1')
				error_flag = mlx_image_to_window (map_data->mlx_ptr, \
					map_data->images[WALL], j * TLE, i * TLE);
			else if (map_data->map[i][j] == 'C')
				error_flag = mlx_image_to_window (map_data->mlx_ptr, \
					map_data->images[COLLEC], j * TLE, i * TLE);
			else if (map_data->map[i][j] == 'E')
				error_flag = mlx_image_to_window (map_data->mlx_ptr, \
					map_data->images[EXTS], j * TLE, i * TLE);
			if (error_flag == -1)
				return (1);
		}
	}
	return (0);
}

int	initiate_window(t_data *map_data)
{
	map_data->cur_coll = 0;
	map_data->move_count = 0;
	map_data->mlx_ptr = mlx_init(map_data->length * TLE,
			map_data->height * TLE, "so long", false);
	if (map_data->mlx_ptr == NULL)
		ft_error("Memory allocation failure check\n", map_data->map, map_data);
	if (init_images(map_data) == 1)
		ft_error("Failed to load images\n", map_data->map, map_data);
	if (init_map(map_data, -1, -1, 0) == 1)
	{
		mlx_close_window(map_data->mlx_ptr);
		mlx_terminate(map_data->mlx_ptr);
		ft_error("Failed to initialize map\n", map_data->map, map_data);
	}
	init_player(map_data);
	play_game(map_data);
	return (0);
}

void	delete_collect(t_data *map_data)
{
	int		i;
	int		count;

	i = 0;
	count = map_data->coll;
	while (i < count)
	{
		if (map_data->images[COLLEC]->instances[i].y == map_data->images
			[ENTRY]->instances->y && map_data->images[COLLEC]->instances[i].x
			== map_data->images[ENTRY]->instances->x && map_data->images[COLLEC]
			->instances[i].enabled == true)
		{
			count--;
			map_data->images[COLLEC]->instances[i].enabled = false;
		}
		i++;
	}
}

void	check_collect(t_data *map_data)
{
	if (map_data->map[map_data->images[ENTRY]->instances->y / TLE]
		[map_data->images[ENTRY]->instances->x / TLE] == 'C')
	{
		delete_collect(map_data);
		map_data->map[map_data->images[ENTRY]->instances->y / TLE]
		[map_data->images[ENTRY]->instances->x / TLE] = '0';
		map_data->cur_coll++;
	}
	if (map_data->map[map_data->images[ENTRY]->instances->y / TLE]
		[map_data->images[ENTRY]->instances->x / TLE] == 'E')
	{
		if (map_data->coll == map_data->cur_coll)
		{
			mlx_close_window(map_data->mlx_ptr);
		}
	}
}
