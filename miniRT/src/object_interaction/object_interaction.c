/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_interaction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:17:10 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/05 12:53:52 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "float.h"

bool	object_in_shadow(t_float_three point, t_win *win, float dist, \
	t_light *light)
{
	t_obj_in_shadow	s;

	init_obj_in_shadow_struct(&s, point, win, light);
	while (s.sp != NULL)
	{
		if (sphere_intersection(s.ray_shadow, &s.a, s.sp, 0) && s.a < dist)
			return (true);
		s.sp = s.sp->next;
	}
	while (s.pl != NULL)
	{
		if (plane_intersection(s.ray_shadow, &s.a, s.pl) && s.a < dist)
			return (true);
		s.pl = s.pl->next;
	}
	while (s.cy != NULL)
	{
		if (cylinder_intersection(s.ray_shadow, &s.a, s.cy, &s.x) && s.a < dist)
			return (true);
		s.cy = s.cy->next;
	}
	return (false);
}

// gets the pixel lightvalue for a light.
// BRIGTNESS is a multiplier for every light and is a bit arbitriary.
t_colour_f	add_light(t_float_three point, t_win *win, \
	t_float_three normal_to_object, t_light *light)
{
	t_float_three	to_light;
	float			dist_to_light;

	if (light == NULL)
		return (colf_store(0, 0, 0));
	to_light = vec_sub(light->pos, point);
	dist_to_light = vec_length(to_light);
	to_light = vec_normalize(to_light);
	if (object_in_shadow(point, win, dist_to_light, light))
		return (colf_store(0, 0, 0));
	return (colf_mul(col_to_colf(light->col),
			(fmaxf(vec_dot(normal_to_object, to_light), 0)
				* light->intensity * BRIGHTNESS)
			/ (dist_to_light * dist_to_light)));
}

t_colour_f	get_diffused_colour(t_float_three point, t_win *win, \
	t_float_three normal_to_object)
{
	t_colour_f	total;
	t_light		*light;

	total = colf_store(0, 0, 0);
	light = win->scene->lights;
	while (light != NULL)
	{
		total = colf_add(total, add_light(point, win, normal_to_object, light));
		light = light->next;
	}
	return (total);
}

t_colour	compute_color(	t_float_three point,
							t_colour color, t_win *win,
							t_float_three normal_to_object)
{
	t_colour		final_color;
	t_colour_f		ambient_color;
	t_colour_f		diffused;

	ambient_color = colf_mul(col_to_colf(win->scene->ambient_lighting.col),
			win->scene->ambient_lighting.intensity);
	diffused = get_diffused_colour(point, win, normal_to_object);
	diffused.r *= (float)color.r / 255.0f;
	diffused.g *= (float)color.g / 255.0f;
	diffused.b *= (float)color.b / 255.0f;
	ambient_color.r *= (float)color.r / 255.0f;
	ambient_color.g *= (float)color.g / 255.0f;
	ambient_color.b *= (float)color.b / 255.0f;
	if (!LINEAR_COLOUR)
		diffused = colf_pretty(diffused);
	final_color = colf_to_col(ambient_color);
	final_color = col_add(final_color, colf_to_col(diffused));
	return (col_clamp(final_color, 0, 255));
}

t_colour	get_object_intersection(t_ray ray, t_win *win)
{
	t_obj_intersection	obj;

	obj.hit = false;
	obj.min = FLT_MAX;
	obj.color = col_store(0, 0, 0);
	obj.cy_hit_type = 0;
	obj.object_type = 0;
	get_sphere_intersection(&obj, ray, win, win->scene->spheres);
	get_cylinder_intersection(&obj, ray, win, win->scene->cylinders);
	get_plane_intersection(&obj, ray, win, win->scene->planes);
	if (obj.hit == true)
		obj.color = compute_color(obj.point, obj.color, win, \
			obj.normal_to_object);
	else
		obj.color = col_store(0, 0, 0);
	return (obj.color);
}
