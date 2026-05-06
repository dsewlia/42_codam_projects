/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_interaction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:35:48 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/05 12:55:42 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "float.h"

float	get_side_cy_intersection(t_ray ray, t_cylinder *cy, float a, float b)
{
	float			dist_side;
	float			c;
	t_float_three	d;
	t_float_three	delta;
	float			proj;

	d = vec_sub(ray.direction, vec_mul(cy->rot, \
		vec_dot(ray.direction, cy->rot)));
	delta = vec_sub(vec_sub(ray.origin, cy->pos), vec_mul(cy->rot, \
		vec_dot(vec_sub(ray.origin, cy->pos), cy->rot)));
	a = vec_dot(d, d);
	b = 2 * (vec_dot(d, delta));
	c = vec_dot(delta, delta) - ((cy->diameter * cy->diameter) / 4);
	if (fabs(a) < EPSILON)
		return (-1);
	dist_side = solve_quad(a, b, c);
	if (dist_side < 0)
		return (-1);
	proj = vec_dot(vec_sub(vec_add(ray.origin, \
		vec_mul(ray.direction, dist_side)), cy->pos), cy->rot);
	if (proj < -cy->height / 2 - EPSILON || proj > cy->height / 2 + EPSILON)
		return (-1);
	return (dist_side);
}

float	get_cap_cy_intersection(t_ray ray, t_cylinder *cy)
{
	t_cy_intersection	c;
	int					i;
	float				base;

	base = 0;
	i = -1;
	c.dist_min = FLT_MAX;
	c.intersection = false;
	while (i <= 1)
	{
		c.c = vec_add(cy->pos, vec_mul(cy->rot, i * cy->height / 2));
		base = vec_dot(ray.direction, cy->rot);
		if (fabs(base) > EPSILON)
		{
			c.dist_cap = vec_dot(vec_sub(c.c, ray.origin), cy->rot) / base;
			if (c.dist_cap > 0)
			{
				get_cap_cy_dist(ray, &c, cy);
			}
		}
		i += 2;
	}
	return (get_cap_dist(c.intersection, c.dist_min));
}

bool	cylinder_intersection(t_ray ray, float *dist, t_cylinder *cy, \
	int *cy_hit_type)
{
	float	dist_cap;
	float	dist_side;

	dist_cap = 0;
	dist_side = 0;
	dist_cap = get_cap_cy_intersection(ray, cy);
	dist_side = get_side_cy_intersection(ray, cy, 0, 0);
	if (dist_cap > EPSILON && dist_side > EPSILON)
	{
		if (dist_cap < dist_side)
			return (*dist = dist_cap, *cy_hit_type = CY_CAP, true);
		else
			return (*dist = dist_side, *cy_hit_type = CY_SIDE, true);
	}
	else if (dist_side > EPSILON)
		return (*dist = dist_side, *cy_hit_type = CY_SIDE, true);
	else if (dist_cap > EPSILON)
		return (*dist = dist_cap, *cy_hit_type = CY_CAP, true);
	return (false);
}

void	get_cylinder_intersection(t_obj_intersection *o, t_ray ray, \
	t_win *win, t_cylinder *cy)
{
	cy = win->scene->cylinders;
	while (cy != NULL)
	{
		if (cylinder_intersection(ray, &o->dist, cy, &o->cy_hit_type) \
			&& o->dist < o->min)
		{
			o->min = o->dist;
			o->hit = true;
			o->object_type = CYLINDER;
			o->point = vec_add(ray.origin, vec_mul(ray.direction, o->dist));
			if (o->cy_hit_type == CY_SIDE)
				o->normal_to_object = vec_normalize (vec_sub(vec_sub(o->point, \
					cy->pos), vec_mul(cy->rot, vec_dot(vec_sub(o->point, \
					cy->pos), cy->rot))));
			else
			{
				if (vec_dot(vec_sub(o->point, cy->pos), cy->rot) > 0)
					o->normal_to_object = vec_normalize(cy->rot);
				else
					o->normal_to_object = vec_normalize(vec_mul(cy->rot, -1));
			}
			o->color = cy->col;
		}
		cy = cy->next;
	}
}
