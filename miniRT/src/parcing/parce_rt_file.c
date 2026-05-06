/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_rt_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:43 by driemers          #+#    #+#             */
/*   Updated: 2025/04/22 16:48:54 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	execute_object_function(char **str, int *fail,
			int index, t_scene *scene);
void	execute_object_parceing(char **str, int *fail,
			char *order, t_scene *scene);
int		check_element_count(int *element_count);

char	*read_file(int fd)
{
	char	buffer[READ_SIZE + 1];
	char	*tmp;
	char	*str;

	tmp = NULL;
	clear_str(buffer, READ_SIZE);
	if (read(fd, buffer, READ_SIZE) < 0)
		return (NULL);
	buffer[READ_SIZE] = 0;
	str = ft_strdup(buffer);
	while (read(fd, buffer, READ_SIZE) > 0)
	{
		buffer[READ_SIZE] = 0;
		tmp = str;
		if (str != NULL)
			str = ft_strjoin(tmp, buffer);
		if (tmp != NULL)
			free (tmp);
		if (str == NULL)
			return (NULL);
		clear_str(buffer, READ_SIZE);
	}
	if (DEBUG)
		printf("STR: %s\n", str);
	return (str);
}

char	*add_element(char *order, char *str,
					int *element_count)
{
	static bool	element_instancing[ELEMENTS]
		= {false, false, MUTIBLE_LIGHTS, true, true, true};
	int			index;

	index = myenum(*str, ELEMENT_IDS);
	element_count[index] += 1;
	if (element_count[index] > 1
		&& element_instancing[index] == false)
		return (print_err_null("Invaid instancing!\n"));
	order = add_char(*str, order);
	if (order == NULL)
		return (print_err_null(ERR_MEM_FAIL));
	if (PRINT_DATA)
		printf("ADD ELEMENT: %c : COUNT: %i \n",
			*str, element_count[index]);
	return (order);
}

// I could have done function pointers if polymorfism was a thing in c...
// (insead of a char array)
// element_instancing means wheter a element can have multible incstances.
// Everything is static to save space for norm reasons,
// the function will only be called ones so its fine.
// And I wand to keep my debug messages!
char	*get_order(char *str)
{
	static int	element_count[ELEMENTS] = {0, 0, 0, 0, 0, 0};
	static char	*order = NULL;
	static char	last_char = '\n';

	while (*str != 0)
	{
		if (last_char == '\n' && ft_strchr(ELEMENT_IDS, *str) != NULL)
		{
			order = add_element(order, str, element_count);
			if (order == NULL)
				return (NULL);
		}
		last_char = *str;
		str++;
	}
	if (order == NULL)
		return (print_err_null("Empty file!\n"));
	if (DEBUG)
		printf("\nORDER: %s\n\n", order);
	if (check_element_count(element_count) == 0)
	{
		free (order);
		return (print_err_null("File is lacking maditory elements!\n"));
	}
	return (order);
}

int	parce_file(char *file, t_scene *scene)
{
	char	**str;
	int		fail;
	char	*order;

	fail = 0;
	str = malloc(sizeof(char *));
	if (str == NULL)
		return (print_err(ERR_MEM_FAIL));
	*str = file;
	order = get_order(*str);
	if (order == NULL)
		fail = 1;
	execute_object_parceing(str, &fail, order, scene);
	while (**str != 0 && fail == 0)
	{
		if (**str != '\n' && ft_isprint(**str))
			print_err_fail(ERR_INVALID_CHAR, &fail);
		*str += 1;
	}
	proper_free(order);
	free (str);
	if (fail == 1)
		return (0);
	return (1);
}

// returns null if parce_file fails
t_scene	*get_scene_data(int fd)
{
	t_scene	*scene;
	char	*file;

	file = read_file(fd);
	if (file == NULL)
		return (NULL);
	scene = malloc(sizeof(t_scene));
	if (scene == NULL)
	{
		free (file);
		return (NULL);
	}
	scene->lights = NULL;
	scene->spheres = NULL;
	scene->planes = NULL;
	scene->cylinders = NULL;
	if (parce_file(file, scene) == 0)
	{
		free_scene(scene);
		scene = NULL;
	}
	free(file);
	return (scene);
}
