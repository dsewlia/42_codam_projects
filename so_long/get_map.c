/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:29:43 by dsewlia           #+#    #+#             */
/*   Updated: 2025/03/27 19:20:08 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*typedef struct s_data
{
	mlx_t			*mlx_ptr;
	int				height;
	int				length;
	char			**map;
	int				coll;
	int				cur_coll;
	int				move_count;
	int				entry;
	int				ext;
	mlx_texture_t	*textures[5];
	mlx_image_t		*images[5];
}	t_data;*/

void	get_initial_map_data(t_data *map_data)
{
	map_data->length = 0;
	map_data->height = 0;
	map_data->coll = 0;
	map_data->entry = 0;
	map_data->ext = 0;
	map_data->map = NULL;
	map_data->mlx_ptr = NULL;
	map_data->cur_coll = 0;
	map_data->move_count = 0;
}

char	**get_map_util(t_data *map_data, char *map_sd, int i)
{
	char	**map;

	map = ft_split(map_sd, '\n');
	free (map_sd);
	if (map == NULL)
		ft_error("memory allocation failed\n", map, map_data);
	while (map[i] != NULL)
		i++;
	if (i < 3)
		ft_error("Invalid map\n", map, map_data);
	map_data->height = i;
	while (map[0][map_data->length] != '\0')
		map_data->length++;
	return (map);
}

char	**get_map(t_data *map_data, char **argv, int i, int j)
{
	int		fd;
	char	*map_sd;

	while (argv[1][i] != '\0')
		i++;
	j = 0;
	if (i < 5 || argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e'
		|| argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
		ft_error("wrong file format\n", NULL, map_data);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("fd less than 0\n", NULL, map_data);
	map_sd = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	i = 0;
	while (read(fd, &map_sd[i * BUFFER_SIZE], BUFFER_SIZE) == BUFFER_SIZE)
	{
		i++;
		map_sd = ft_cust_realloc(map_sd, i + 1);
		if (map_sd == NULL)
		{
			free (map_data);
			ft_error("memory reallocation failed\n", NULL, map_data);
		}
	}
	return (get_map_util(map_data, map_sd, 0));
}

void	create_map_copy(t_data *map_data, char **map, t_path *path_data,
		char **dup_map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_data->height)
	{
		j = -1;
		while (++j < map_data->length)
		{
			dup_map[i][j] = map[i][j];
			if (map[i][j] == 'E')
			{
				path_data->ent_x = i;
				path_data->ent_y = j;
			}
		}
	}
}

char	**get_dup_map(t_data *map_data, char **map, t_path *path_data,
		char **dup_map)
{
	int		i;

	i = -1;
	while (++i < map_data->height)
	{
		dup_map[i] = ft_calloc(sizeof(char), (map_data->length + 1));
		if (dup_map[i] == NULL)
		{
			while (--i >= 0)
				free (dup_map[i]);
			free (dup_map);
			free (path_data);
			ft_error("memory allocation failed\n", map, map_data);
		}
	}
	create_map_copy(map_data, map, path_data, dup_map);
	map_data->map = map;
	return (dup_map);
}
