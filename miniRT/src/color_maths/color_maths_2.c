/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_maths_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:43:02 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/30 15:23:23 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//returns dot product of a and b
float	col_dot(t_colour a, t_colour b)
{
	return ((a.r * b.r) + (a.g * b.g) + (a.b * b.b));
}

//returns cross product of a and b
t_colour	col_cross(t_colour a, t_colour b)
{
	float	x;
	float	y;
	float	z;

	x = (a.g * b.b) - (a.b * b.g);
	y = (a.b * b.r) - (a.r * b.b);
	z = (a.r * b.g) - (a.g * b.r);
	return (col_store(x, y, z));
}

//returns the normilized vector
t_colour	col_normalize(t_colour a)
{
	float	scale;

	scale = 1 / (sqrtf((a.r * a.r) + (a.g * a.g) + (a.b * a.b)));
	return (col_mul(a, scale));
}

t_colour	col_clamp(t_colour col, float min, float max)
{
	col.r = fminf(fmaxf(col.r, min), max);
	col.g = fminf(fmaxf(col.g, min), max);
	col.b = fminf(fmaxf(col.b, min), max);
	return (col);
}

	// ret_val.r = log(log(log(log(ret_val.r + 1) + 1) + 1) + 1) * 1.2;
	// ret_val.g = log(log(log(log(ret_val.g + 1) + 1) + 1) + 1) * 1.2;
	// ret_val.b = log(log(log(log(ret_val.b + 1) + 1) + 1) + 1) * 1.2;
// colf_pretty makes the lighting non linear.
// it also adds a litlle bit of random noise to breakup ugly colour banding :)
t_colour_f	colf_pretty(t_colour_f col)
{
	t_colour_f	ret_val;

	ret_val = col;
	ret_val.r /= COLOUR_MAX_F;
	ret_val.g /= COLOUR_MAX_F;
	ret_val.b /= COLOUR_MAX_F;
	ret_val.r = tanh(tanh(tanh(tanh(tanh(tanh(tanh(ret_val.r))))))) * 1.2;
	ret_val.g = tanh(tanh(tanh(tanh(tanh(tanh(tanh(ret_val.g))))))) * 1.2;
	ret_val.b = tanh(tanh(tanh(tanh(tanh(tanh(tanh(ret_val.b))))))) * 1.2;
	ret_val.r *= COLOUR_MAX_F;
	ret_val.g *= COLOUR_MAX_F;
	ret_val.b *= COLOUR_MAX_F;
	ret_val.r += (float)((int)(col.r * col.r * 100000) % 5) / 5.0f;
	ret_val.g += (float)((int)(col.g * col.g * 100000) % 5) / 5.0f;
	ret_val.b += (float)((int)(col.b * col.b * 100000) % 5) / 5.0f;
	return (ret_val);
}
