/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:27:38 by dsewlia           #+#    #+#             */
/*   Updated: 2025/02/21 12:33:46 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_boundaries(t_data *map_data, char **map)
{
	int		i;

	i = 0;
	while (i < map_data->length)
	{
		if (map[0][i] != '1' || map[map_data->height - 1][i] != '1')
			ft_error("map error-boundaries\n", map, map_data);
		i++;
	}
	i = 0;
	while (i < map_data->height)
	{
		if (map[i][0] != '1' || map[i][map_data->length - 1] != '1')
			ft_error("map error-boundaries\n", map, map_data);
		i++;
	}
}

void	check_map(t_data *map_data, char **map, int i, int j)
{
	while (i < map_data->height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				map_data->coll++;
			else if (map[i][j] == 'P')
				map_data->entry++;
			else if (map[i][j] == 'E')
				map_data->ext++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				ft_error("map error - invalid character\n", map, map_data);
			j++;
		}
		if (j != map_data->length)
			ft_error("map error - not a rectangle\n", map, map_data);
		i++;
	}
	if (map_data->coll < 1 || map_data->entry != 1 || map_data->ext != 1)
		ft_error("map error\n", map, map_data);
	check_boundaries(map_data, map);
}

int	traverse_path(char **dup_map, t_path *path_data, int x, int y)
{
	if (path_data->target == path_data->coll && path_data->ext == 1)
		return (0);
	if (dup_map[x][y] == '1')
		return (1);
	else if (dup_map[x][y] == 'C')
		path_data->coll++;
	else if (dup_map[x][y] == 'E')
		path_data->ext++;
	dup_map[x][y] = '1';
	if (traverse_path(dup_map, path_data, x + 1, y) == 0
		|| traverse_path(dup_map, path_data, x - 1, y) == 0
		|| traverse_path(dup_map, path_data, x, y + 1) == 0
		|| traverse_path(dup_map, path_data, x, y - 1) == 0)
		return (0);
	return (1);
}

void	ft_free_dup_map(char **map, t_data *map_data)
{
	int		i;

	i = 0;
	while (i < map_data->height)
	{
		free (map[i]);
		i++;
	}
	free (map);
}

void	check_path(t_data *map_data, char **map, int i)
{
	char	**dup_map;
	t_path	*path_data;

	dup_map = (char **)ft_calloc(sizeof(char *), (map_data->height + 1));
	if (dup_map == NULL)
		ft_error("memory allocation failed\n", map, map_data);
	path_data = ft_calloc(sizeof(t_path), 1);
	if (path_data == NULL)
	{
		free(dup_map);
		ft_error("memmory allocation failed", map, map_data);
	}
	dup_map = get_dup_map(map_data, map, path_data, dup_map);
	dup_map[map_data->height] = NULL;
	path_data->target = map_data->coll;
	path_data->coll = 0;
	path_data->ext = 0;
	path_data->length = map_data->length;
	path_data->height = map_data->height;
	i = traverse_path(dup_map, path_data, path_data->ent_x, path_data->ent_y);
	ft_free_dup_map(dup_map, map_data);
	free(path_data);
	if (i == 1)
		ft_error("map error - invalid path", map, map_data);
}
