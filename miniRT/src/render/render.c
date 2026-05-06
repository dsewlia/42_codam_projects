/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:12:19 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/05 13:21:13 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "float.h"

t_base_camera	build_base_camera(t_win *win, t_scene *scene)
{
	t_base_camera	base;
	t_float_three	up;

	normalize_vectors(win);
	up = vec_store(0, 1, 0);
	if (fabs(vec_dot(up, scene->camera.rot)) == 1)
	{
		up = vec_store(0, 0, 1);
	}
	base.forward = scene->camera.rot;
	base.right = vec_normalize(vec_cross(up, base.forward));
	base.up = vec_normalize(vec_cross(base.forward, base.right));
	return (base);
}

t_uv	get_uv(int x, int y, t_win *win, float fov)
{
	t_uv			uv;
	static float	u_norm = 1;
	static float	v_norm = 1;

	if (u_norm == 1 && v_norm == 1)
	{
		if (win->res_x > win->res_y)
			u_norm = ((float)win->res_x / (float)win->res_y);
		else if (win->res_x != win->res_y)
			v_norm = ((float)win->res_y / (float)win->res_x);
	}
	uv.u = (((2 * (x + 0.5)) / win->res_x) - 1) * (tan(fov * M_PI / 360));
	uv.v = (1 - ((2 * (y + 0.5)) / win->res_y)) * (tan(fov * M_PI / 360));
	uv.u *= u_norm;
	uv.v *= v_norm;
	return (uv);
}

unsigned int	get_color(t_base_camera base, t_win *win, int x, int y)
{
	t_uv			uv;
	t_ray			ray;
	t_colour		color;

	uv = get_uv(x, y, win, win->scene->camera.fov);
	ray.origin = win->scene->camera.pos;
	ray.direction = vec_normalize(vec_add(vec_mul(base.right, uv.u), \
		vec_add(vec_mul(base.up, uv.v), base.forward)));
	color = get_object_intersection(ray, win);
	return (color.r << 16 | color.g << 8 | color.b);
}
//color = (vector multiplication of color and ambient_ratio) + ambient_color

void	normalize_vectors(t_win	*win)
{
	t_cylinder	*cy;
	t_plane		*pl;

	cy = win->scene->cylinders;
	pl = win->scene->planes;
	while (cy != NULL)
	{
		cy->rot = vec_normalize(cy->rot);
		cy = cy->next;
	}
	while (pl != NULL)
	{
		pl->normal = vec_normalize(pl->normal);
		pl = pl->next;
	}
}

// render fuction will fill the screen one vertical line at a time.
// and it keeps track of that with static y value.
int	render(t_win *win)
{
	static t_base_camera	base;
	int						x;
	static int				y = 0;

	if (y >= win->res_y)
		return (0);
	if (y == 0)
		base = build_base_camera(win, win->scene);
	x = -1;
	while (++x < win->res_x)
		put_pixel(&win->img, x, y, get_color(base, win, x, y));
	if (PRINT_PROGRESS)
		printf("%d%% done\n", (y + 1) / (win->res_y / 100));
	y++;
	return (y);
}
