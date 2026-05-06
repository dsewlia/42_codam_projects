/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_interaction_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:23:45 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/05 12:55:19 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "float.h"

float	get_cap_dist(bool intersection, float dist_min)
{
	if (intersection == true)
		return (dist_min);
	return (-1);
}

void	init_obj_in_shadow_struct(t_obj_in_shadow *s, t_float_three point, \
	t_win *win, t_light *light)
{
	s->sp = win->scene->spheres;
	s->pl = win->scene->planes;
	s->cy = win->scene->cylinders;
	s->light_source = vec_normalize(vec_sub(light->pos, point));
	s->ray_shadow.origin = vec_add(point, vec_mul(s->light_source, 0.001));
	s->ray_shadow.direction = s->light_source;
}

float	solve_quad(float a, float b, float c)
{
	float	d1;
	float	d2;

	if (fabs(a) < EPSILON || (b * b) - (4 * a * c) < 0)
		return (-1);
	d1 = ((b * -1) - sqrtf((b * b) - (4 * a * c))) / (2 * a);
	d2 = ((b * -1) + sqrtf((b * b) - (4 * a * c))) / (2 * a);
	if (d1 > 0 && d2 > 0)
	{
		if (d1 < d2)
			return (d1);
		else
			return (d2);
	}
	else if (d1 > 0)
		return (d1);
	else if (d2 > 0)
		return (d2);
	return (-1);
}

t_float_three	perpendicular_vector(t_float_three v)
{
	if (fabs(v.x) < fabs(v.y) && fabs(v.x) < fabs(v.z))
		return (vec_cross(v, (t_float_three){1, 0, 0}));
	else if (fabs(v.y) < fabs(v.z))
		return (vec_cross(v, (t_float_three){0, 1, 0}));
	else
		return (vec_cross(v, (t_float_three){0, 0, 1}));
}

void	get_cap_cy_dist(t_ray ray, t_cy_intersection *c, t_cylinder *cy)
{
	t_float_three		to_p;
	t_float_three		u;
	t_float_three		v;
	float				x;
	float				y;

	c->p = vec_add(ray.origin, vec_mul(ray.direction, c->dist_cap));
	to_p = vec_sub(c->p, c->c);
	u = vec_normalize(perpendicular_vector(cy->rot));
	v = vec_normalize(vec_cross(cy->rot, u));
	x = vec_dot(to_p, u);
	y = vec_dot(to_p, v);
	if (((x * x) + (y * y)) <= ((cy->diameter * cy->diameter) / 4) \
		&& c->dist_cap < c->dist_min)
	{
		c->intersection = true;
		c->dist_min = c->dist_cap;
	}
}
