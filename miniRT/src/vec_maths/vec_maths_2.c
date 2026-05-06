/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_maths_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:56:30 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/24 20:20:29 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//returns dot product of a and b
float	vec_dot(t_float_three a, t_float_three b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

//returns cross product of a and b
t_float_three	vec_cross(t_float_three a, t_float_three b)
{
	float	x;
	float	y;
	float	z;

	x = (a.y * b.z) - (a.z * b.y);
	y = (a.z * b.x) - (a.x * b.z);
	z = (a.x * b.y) - (a.y * b.x);
	return (vec_store(x, y, z));
}

//returns the normilized vector
t_float_three	vec_normalize(t_float_three a)
{
	float	scale;

	scale = 1 / (sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
	return (vec_mul(a, scale));
}

//rotates vector v around axis k by angle(in degrees)
//Uses Rodriguez's formula = vcos 0 + (1 - cos 0)(k.v)k + (k X V)sin 0
t_float_three	vec_rotate(t_float_three v, t_float_three k, float angle)
{
	double			radiun;
	t_float_three	a;
	t_float_three	b;
	t_float_three	c;

	radiun = angle * (M_PI / 180.0);
	a = vec_mul(v, cos(radiun));
	b = vec_mul(vec_mul(k, vec_dot(k, v)), (1 - cos(radiun)));
	c = vec_mul(vec_cross(k, v), sin(radiun));
	return (vec_add(a, vec_add(b, c)));
}
