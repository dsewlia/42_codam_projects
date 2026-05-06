/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_linked_lists.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:47:56 by driemers          #+#    #+#             */
/*   Updated: 2025/04/22 15:39:49 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>
#include <stdio.h>

//this whole file would not be needed if polymorfism was a thing AAARRGGGHHHH!
//and also in c++ i would use vectors instead of linked lists.
// _of = object_fuction, can't think of a better name.

int	light_of(char **str, int *fail, t_scene *scene)
{
	static t_light	*l_ptr;

	if (*fail != 0)
		return (0);
	if (scene->lights == NULL)
	{
		scene->lights = parce_light(str, fail);
		l_ptr = scene->lights;
	}
	else
	{
		l_ptr->next = parce_light(str, fail);
		l_ptr = l_ptr->next;
	}
	return (1);
}

int	sphere_of(char **str, int *fail, t_scene *scene)
{
	static t_sphere	*s_ptr;

	if (*fail != 0)
		return (0);
	if (scene->spheres == NULL)
	{
		scene->spheres = parce_sphere(str, fail);
		s_ptr = scene->spheres;
	}
	else
	{
		s_ptr->next = parce_sphere(str, fail);
		s_ptr = s_ptr->next;
	}
	return (1);
}

int	plane_of(char **str, int *fail, t_scene *scene)
{
	static t_plane	*p_ptr;

	if (*fail != 0)
		return (0);
	if (scene->planes == NULL)
	{
		scene->planes = parce_plane(str, fail);
		p_ptr = scene->planes;
	}
	else
	{
		p_ptr->next = parce_plane(str, fail);
		p_ptr = p_ptr->next;
	}
	return (1);
}

int	cylinder_of(char **str, int *fail, t_scene *scene)
{
	static t_cylinder	*c_ptr;

	if (*fail != 0)
		return (0);
	if (scene->cylinders == NULL)
	{
		scene->cylinders = parce_cylinder(str, fail);
		c_ptr = scene->cylinders;
	}
	else
	{
		c_ptr->next = parce_cylinder(str, fail);
		c_ptr = c_ptr->next;
	}
	return (1);
}
