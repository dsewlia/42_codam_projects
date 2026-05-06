/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:29 by dsewlia           #+#    #+#             */
/*   Updated: 2025/03/27 13:41:07 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, char **map, t_data *map_data)
{
	int		i;

	i = -1;
	if (map != NULL)
	{
		while (map[++i] != NULL)
			free (map[i]);
		free (map);
	}
	if (map_data != NULL)
		free (map_data);
	i = 0;
	write (2, "Error\n", 6);
	while (str != NULL && str[i] != '\0')
	{
		write (2, &str[i], 1);
		i++;
	}
	exit (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	long int		n1;
	long int		n2;
	long int		n3;
	unsigned char	*a;
	int				i;

	n1 = nmemb;
	n2 = size;
	n3 = n1 * n2;
	if (nmemb <= 0 || size <= 0)
		return (malloc(1));
	if (n3 > 2147483647)
		return (NULL);
	a = (unsigned char *)malloc(n3);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < n3)
	{
		a[i] = 0;
		i++;
	}
	return ((void *)a);
}

char	*ft_cust_realloc(char *str, int i)
{
	int		j;
	char	*new_str;

	j = 0;
	new_str = ft_calloc(sizeof(char), ((BUFFER_SIZE * i) + 1));
	if (new_str == NULL)
	{
		free (str);
		return (NULL);
	}
	if (str != NULL)
	{
		while (str[j] != '\0')
		{
			new_str[j] = str[j];
			j++;
		}
	}
	new_str[j] = '\0';
	free (str);
	return (new_str);
}

void	free_all(t_data *map_data)
{
	int		i;

	i = 0;
	while (i < map_data->height)
	{
		free (map_data->map[i]);
		i++;
	}
	free (map_data->map);
	mlx_terminate(map_data->mlx_ptr);
	free (map_data);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_data	*map_data;

	if (argc != 2 || argv[1] == NULL || argv[1][0] == '\0')
		ft_error("argument mismatch\n", NULL, NULL);
	map_data = ft_calloc(sizeof(t_data), 1);
	if (map_data == NULL)
		ft_error("memory allocation failed\n", NULL, map_data);
	get_initial_map_data(map_data);
	map = get_map(map_data, argv, 0, 0);
	check_map(map_data, map, 0, 0);
	check_path(map_data, map, 0);
	if (initiate_window(map_data) == 1)
		return (1);
	return (0);
}
