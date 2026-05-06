/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:51:52 by dsewlia           #+#    #+#             */
/*   Updated: 2025/03/27 13:50:45 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_textures(t_data *map_data)
{
	mlx_texture_t	**textures;
	int				error_flag;

	error_flag = 0;
	textures = map_data->textures;
	if (textures[0] == NULL || textures[1] == NULL || textures[2] == NULL \
		|| textures[3] == NULL || textures[4] == NULL)
		error_flag = 1;
	if (error_flag == 0)
		return (0);
	if (textures[0] != NULL)
		mlx_delete_texture(textures[0]);
	if (textures[1] != NULL)
		mlx_delete_texture(textures[1]);
	if (textures[2] != NULL)
		mlx_delete_texture(textures[2]);
	if (textures[3] != NULL)
		mlx_delete_texture(textures[3]);
	if (textures[4] != NULL)
		mlx_delete_texture(textures[4]);
	mlx_terminate(map_data->mlx_ptr);
	return (1);
}

int	check_images(t_data *map_data)
{
	mlx_image_t	**images;
	int			error_flag;

	error_flag = 0;
	images = map_data->images;
	if (images[0] == NULL || images[1] == NULL || images[2] == NULL \
		|| images[3] == NULL || images[4] == NULL)
		error_flag = 1;
	if (error_flag == 0)
		return (0);
	if (images[0] != NULL)
		mlx_delete_image(map_data->mlx_ptr, images[0]);
	if (images[1] != NULL)
		mlx_delete_image(map_data->mlx_ptr, images[1]);
	if (images[2] != NULL)
		mlx_delete_image(map_data->mlx_ptr, images[2]);
	if (images[3] != NULL)
		mlx_delete_image(map_data->mlx_ptr, images[3]);
	if (images[4] != NULL)
		mlx_delete_image(map_data->mlx_ptr, images[4]);
	mlx_terminate(map_data->mlx_ptr);
	return (1);
}

void	play_game(t_data *map_data)
{
	mlx_key_hook(map_data->mlx_ptr, &ft_key_hook, map_data);
	mlx_loop(map_data->mlx_ptr);
	free_all(map_data);
}

void	init_player(t_data *map_data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_data->height)
	{
		j = -1;
		while (++j < map_data->length)
		{
			if (map_data->map[i][j] == 'P')
			{
				if (mlx_image_to_window(map_data->mlx_ptr, \
					map_data->images[ENTRY], j * TLE, i * TLE) == -1)
				{
					mlx_close_window(map_data->mlx_ptr);
					mlx_terminate(map_data->mlx_ptr);
					ft_error("Failed to initialize map\n", \
						map_data->map, map_data);
				}
			}
		}
	}
}
