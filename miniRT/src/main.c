/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:40:26 by driemers          #+#    #+#             */
/*   Updated: 2025/04/30 15:07:41 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

void	program_start(unsigned int x, unsigned int y, t_scene *scene);
t_scene	*get_scene_data(int fd);

int	check_arg(char *str)
{
	if (ft_strlen(str) < 3)
		return (print_err(ERR_INCORRECT_ARG));
	if (ft_strncmp(str + ft_strlen(str) - 3, ".rt", 3) != 0)
		return (print_err(ERR_INCORRECT_ARG));
	return (1);
}

// this fuction is just to make sure the linked lists work.
// cylinders is arbitrairy it can be any object.
static void	check_cylinders(t_scene *scene)
{
	t_cylinder	*ptr;

	ptr = scene->cylinders;
	if (ptr != NULL)
		printf("\n%s\n", "CHECK CYLINDERS: ");
	while (ptr != NULL)
	{
		printf("\n%f,%f,%f %f,%f,%f %f %f %u,%u,%u\n",
			ptr->pos.x,
			ptr->pos.y,
			ptr->pos.z,
			ptr->rot.x,
			ptr->rot.y,
			ptr->rot.z,
			ptr->diameter,
			ptr->height,
			ptr->col.r,
			ptr->col.g,
			ptr->col.b);
		ptr = ptr->next;
	}
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	int		file_fd;

	if (argc != 2)
		return (print_err(ERR_INCORRECT_ARG));
	if (check_arg(argv[1]) == 0)
		return (0);
	file_fd = open(argv[1], O_RDONLY);
	if (file_fd < 0)
		return (print_err(ERR_NO_SUCH_FILE));
	scene = get_scene_data(file_fd);
	close(file_fd);
	if (scene == NULL)
		return (print_err(ERR_SETUP_CANNED));
	if (DEBUG)
		check_cylinders(scene);
	program_start(SCREEN_X * SCREEN_SCALE, SCREEN_Y * SCREEN_SCALE, scene);
}
