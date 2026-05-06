/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:16:42 by dsewlia           #+#    #+#             */
/*   Updated: 2025/03/28 11:25:00 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# define BUFFER_SIZE 10000
# define FLOOR 0
# define WALL 1
# define COLLEC 2
# define ENTRY 3
# define EXTS 4
# define FLOOR_PATH "./assets/floor.xpm"
# define WALL_PATH "./assets/wall.xpm"
# define PLAYER_PATH "./assets/cat.xpm"
# define COLLECTIBLE_PATH "./assets/fish.xpm"
# define EXIT_PATH "./assets/end.xpm"
# define TLE 128

typedef struct s_data
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
}	t_data;

typedef struct s_path
{
	int		ent_x;
	int		ent_y;
	int		target;
	int		coll;
	int		ext;
	int		length;
	int		height;
}	t_path;

int		ft_printf(const char *format, ...);
char	**ft_split(char const *s, char c);
void	ft_error(char *str, char **map, t_data *map_data);
void	get_initial_map_data(t_data *map_data);
char	*ft_cust_realloc(char *str, int i);
char	**get_map_util(t_data *map_data, char *map_sd, int i);
char	**get_map(t_data *map_data, char **argv, int i, int j);
void	create_map_copy(t_data *map_data, char **map, t_path *path_data,
			char **dup_map);
char	**get_dup_map(t_data *map_data, char **map, t_path *path_data,
			char **dup_map);
void	check_boundaries(t_data *map_data, char **map);
void	check_map(t_data *map_data, char **map, int i, int j);
int		traverse_path(char **dup_map, t_path *path_data, int x, int y);
void	check_path(t_data *map_data, char **map, int i);
int		init_images(t_data *map_data);
int		init_map(t_data *map_data, int i, int j, int error_flag);
void	move_up(t_data *map_data);
void	move_down(t_data *map_data);
void	move_left(t_data *map_data);
void	move_right(t_data *map_data);
void	delete_collect(t_data *map_data);
void	check_collect(t_data *map_data);
void	ft_key_hook(mlx_key_data_t keydata, void *ptr);
void	free_all(t_data *map_data);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_textures(t_data *map_data);
int		check_images(t_data *map_data);
void	play_game(t_data *map_data);
void	init_player(t_data *map_data);
int		initiate_window(t_data *map_data);
int		main(int argc, char **argv);

#endif
