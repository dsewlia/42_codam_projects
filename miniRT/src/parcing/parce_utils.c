/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:38:45 by driemers          #+#    #+#             */
/*   Updated: 2025/04/22 15:10:38 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../minirt.h"
#include <stdio.h>

int	light_of(char **str, int *fail, t_scene *scene);
int	sphere_of(char **str, int *fail, t_scene *scene);
int	plane_of(char **str, int *fail, t_scene *scene);
int	cylinder_of(char **str, int *fail, t_scene *scene);

int	myenum(char c, char *my_enum)
{
	int	index;

	index = 0;
	while (my_enum[index] != 0)
	{
		if (c == my_enum[index])
			break ;
		index++;
	}
	return (index);
}

char	*add_char(char c, char *str)
{
	char	*new_s;
	char	append[2];

	if (str == NULL)
	{
		new_s = malloc(sizeof(char) * 2);
		if (new_s == NULL)
			return (NULL);
		new_s[0] = c;
		new_s[1] = 0;
		return (new_s);
	}
	append[0] = c;
	append[1] = 0;
	new_s = ft_strjoin(str, append);
	free (str);
	return (new_s);
}

// this would be a lot cleaner with fuction pointers,
// but since they all have different return structs, i cant...
// no polymorfism :(
void	execute_object_function(char **str, int *fail,
								int index, t_scene *scene)
{
	if (index == 0)
		scene->ambient_lighting = parce_ambient_light(str, fail);
	else if (index == 1)
		scene->camera = parce_cam(str, fail);
	else if (index == 2)
		light_of(str, fail, scene);
	else if (index == 3)
		sphere_of(str, fail, scene);
	else if (index == 4)
		plane_of(str, fail, scene);
	else if (index == 5)
		cylinder_of(str, fail, scene);
}

void	execute_object_parceing(char **str, int *fail,
								char *order, t_scene *scene)
{
	while (*fail == 0 && *order != 0)
	{
		execute_object_function(str, fail,
			myenum(*order, ELEMENT_IDS), scene);
		order++;
	}
}

int	check_element_count(int *element_count)
{
	int			index;
	static bool	is_element_manditory[ELEMENTS]
		= {true, true, false, false, false, false};

	index = 0;
	while (index < ELEMENTS)
	{
		if (is_element_manditory[index] == true
			&& element_count[index] < 1)
			return (0);
		index++;
	}
	return (1);
}
