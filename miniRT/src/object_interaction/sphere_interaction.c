/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_interaction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:05:36 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/30 13:27:31 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool	sphere_intersection(t_ray ray, float *dist, t_sphere *sp, float d1)
{
	t_float_three	virtual;
	float			a;
	float			b;
	float			c;
	float			d2;

	virtual = vec_sub(ray.origin, sp->pos);
	a = vec_dot(ray.direction, ray.direction);
	b = 2 * (vec_dot(virtual, ray.direction));
	c = vec_dot(virtual, virtual) - ((sp->diameter * sp->diameter) / 4);
	if (a == 0 || (((b * b) - (4 * a * c)) < 0))
		return (false);
	d1 = ((b * -1) - sqrtf((b * b) - (4 * a * c))) / (2 * a);
	d2 = ((b * -1) + sqrtf((b * b) - (4 * a * c))) / (2 * a);
	if (d1 <= d2 && d1 > 0)
		return (*dist = d1, true);
	else if (d2 < d1 && d2 > 0)
		return (*dist = d2, true);
	else if (d1 > 0)
		return (*dist = d1, true);
	else if (d2 > 0)
		return (*dist = d2, true);
	return (false);
}

void	get_sphere_intersection(t_obj_intersection *obj, t_ray ray, \
	t_win *win, t_sphere *sp_head)
{
	sp_head = win->scene->spheres;
	while (sp_head != NULL)
	{
		if (sphere_intersection(ray, &obj->dist, sp_head, 0) && \
			obj->dist < obj->min)
		{
			obj->min = obj->dist;
			obj->hit = true;
			obj->object_type = SPHERE;
			obj->point = vec_add(ray.origin, vec_mul(ray.direction, obj->dist));
			obj->normal_to_object = vec_normalize(vec_sub(obj->point, \
				sp_head->pos));
			obj->color = sp_head->col;
		}
		sp_head = sp_head->next;
	}
}
