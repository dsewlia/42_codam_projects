/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_maths_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:54:47 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/24 16:01:59 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//returns the vector t_float_three{x, y, z}
t_float_three	vec_store(float x, float y, float z)
{
	t_float_three	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

//adds 2 vector
t_float_three	vec_add(t_float_three a, t_float_three b)
{
	return (vec_store(a.x + b.x, a.y + b.y, a.z + b.z));
}

//subtracts vector b from vector a
t_float_three	vec_sub(t_float_three a, t_float_three b)
{
	return (vec_store(a.x - b.x, a.y - b.y, a.z - b.z));
}

//Multiples vector a by scalar t
t_float_three	vec_mul(t_float_three a, float t)
{
	return (vec_store(a.x * t, a.y * t, a.z * t));
}

float	vec_length(t_float_three a)
{
	return (sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}
