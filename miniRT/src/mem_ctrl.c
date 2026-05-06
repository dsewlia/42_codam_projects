/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:32:22 by driemers          #+#    #+#             */
/*   Updated: 2025/04/22 15:57:37 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

int	proper_free(void *ptr)
{
	if (ptr == NULL)
		return (0);
	free (ptr);
	return (1);
}

// yet another example of why my object oriented mindset,
// causes some frustrations with c.
// this could be one general fuction if polymorism was a thing in c.
static void	free_scene_util(t_scene *scene)
{
	void		*ptr;
	t_plane		*p_ptr;
	t_cylinder	*c_ptr;

	p_ptr = scene->planes;
	while (p_ptr != NULL)
	{
		ptr = p_ptr;
		p_ptr = p_ptr->next;
		free (ptr);
	}
	c_ptr = scene->cylinders;
	while (c_ptr != NULL)
	{
		ptr = c_ptr;
		c_ptr = c_ptr->next;
		free (ptr);
	}
}

void	free_scene(t_scene *scene)
{
	void		*ptr;
	t_light		*l_ptr;
	t_sphere	*s_ptr;

	l_ptr = scene->lights;
	while (l_ptr != NULL)
	{
		ptr = l_ptr;
		l_ptr = l_ptr->next;
		free (ptr);
	}
	s_ptr = scene->spheres;
	while (s_ptr != NULL)
	{
		ptr = s_ptr;
		s_ptr = s_ptr->next;
		free (ptr);
	}
	free_scene_util(scene);
	free (scene);
}
