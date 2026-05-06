/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_maths_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:39:05 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/30 13:47:08 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//returns the vector t_float_three{x, y, z}
t_colour	col_store(int x, int y, int z)
{
	t_colour	a;

	a.r = x;
	a.g = y;
	a.b = z;
	return (a);
}

//adds 2 vector
t_colour	col_add(t_colour a, t_colour b)
{
	t_colour	ret_val;

	if (a.r + b.r > COLOUR_MAX)
		ret_val.r = COLOUR_MAX;
	else
		ret_val.r += b.r + a.r;
	if (a.g + b.g > COLOUR_MAX)
		ret_val.g = COLOUR_MAX;
	else
		ret_val.g += b.g + a.g;
	if (a.b + b.b > COLOUR_MAX)
		ret_val.b = COLOUR_MAX;
	else
		ret_val.b += b.b + a.b;
	return (ret_val);
}

//subtracts vector b from vector a
t_colour	col_sub(t_colour a, t_colour b)
{
	return (col_store(a.r - b.r, a.g - b.g, a.b - b.b));
}

//Multiples vector a by scalar t
t_colour	col_mul(t_colour a, float t)
{
	return (col_store(a.r * t, a.g * t, a.b * t));
}

//returns the vector t_float_three{x, y, z}
t_colour_f	colf_store(float x, float y, float z)
{
	t_colour_f	a;

	a.r = x;
	a.g = y;
	a.b = z;
	return (a);
}
