/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_maths_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:29:02 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/30 13:32:42 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

t_colour_f	colf_add(t_colour_f a, t_colour_f b)
{
	return (colf_store(a.r + b.r, a.g + b.g, a.b + b.b));
}
// t_colour_f	colf_add(t_colour_f a, t_colour_f b)
// {
// 	t_colour_f	ret_val;

// 	if (a.r + b.r > COLOUR_MAX)
// 		ret_val.r = COLOUR_MAX;
// 	else
// 		ret_val.r += b.r + a.r;
// 	if (a.g + b.g > COLOUR_MAX)
// 		ret_val.g = COLOUR_MAX;
// 	else
// 		ret_val.g += b.g + a.g;
// 	if (a.b + b.b > COLOUR_MAX)
// 		ret_val.b = COLOUR_MAX;
// 	else
// 		ret_val.b += b.b + a.b;
// 	return (ret_val);
// }

//subtracts vector b from vector a
t_colour_f	colf_sub(t_colour_f a, t_colour_f b)
{
	return (colf_store(a.r - b.r, a.g - b.g, a.b - b.b));
}

//Multiples vector a by scalar t
t_colour_f	colf_mul(t_colour_f a, float t)
{
	return (colf_store(a.r * t, a.g * t, a.b * t));
}

t_colour	colf_to_col(t_colour_f col)
{
	t_colour	ret_val;

	ret_val.r = (int)col.r;
	ret_val.g = (int)col.g;
	ret_val.b = (int)col.b;
	return (ret_val);
}

t_colour_f	col_to_colf(t_colour col)
{
	t_colour_f	ret_val;

	ret_val.r = (float)col.r;
	ret_val.g = (float)col.g;
	ret_val.b = (float)col.b;
	return (ret_val);
}
