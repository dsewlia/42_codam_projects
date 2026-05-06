/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_interaction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:50:56 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/05 12:54:45 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool	plane_intersection(t_ray ray, float *dist, t_plane *plane)
{
	float	base;

	base = vec_dot(plane->normal, ray.direction);
	if (fabsf(base) < EPSILON)
		return (false);
	*dist = (vec_dot(vec_sub(plane->pos, ray.origin), plane->normal)) / base;
	if (*dist > 0)
		return (true);
	return (false);
}

void	get_plane_intersection(t_obj_intersection *obj, t_ray ray, \
	t_win *win, t_plane *pl_head)
{
	if (win->scene->planes == NULL)
		return ;
	while (pl_head != NULL)
	{
		if (plane_intersection(ray, &obj->dist, pl_head) && \
			obj->dist < obj->min)
		{
			obj->min = obj->dist;
			obj->hit = true;
			obj->object_type = PLANE;
			obj->point = vec_add(ray.origin, vec_mul(ray.direction, obj->dist));
			obj->normal_to_object = vec_normalize(pl_head->normal);
			obj->color = pl_head->col;
		}
		pl_head = pl_head->next;
	}
}
