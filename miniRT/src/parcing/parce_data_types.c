/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_data_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:30:42 by driemers          #+#    #+#             */
/*   Updated: 2025/04/30 14:19:57 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../libft/libft.h"
#include <stdio.h>

unsigned char	parce_uint_eightbit(char **str, int *fail, int last);
float			parce_float_util(char **str, int *fail, int normalize);
float			parce_float_three_util(char **str, int *fail, int normalize);

// theze functions parce the raw str,
// and turns them in to data types.

// if any of there parcing fuction encounters a problem,
// the fail int will be set to 1

// normalized range is 0 to 255;
t_colour	parce_colour(char **str, int *fail)
{
	t_colour	colour;

	colour.r = 0;
	if (*fail != 0)
		return (colour);
	while (**str == ' ')
		*str += 1;
	colour.r = parce_uint_eightbit(str, fail, 0);
	colour.g = parce_uint_eightbit(str, fail, 0);
	colour.b = parce_uint_eightbit(str, fail, 1);
	if (!ALLOW_BLACK && colour.r == 0 && colour.g == 0 && colour.b == 0)
		print_err_fail("Colours can't be completely dark!\n", fail);
	if (PRINT_DATA)
		printf("%u,%u,%u ",
			colour.r,
			colour.g,
			colour.b);
	return (colour);
}

// normalized range is -1 to 1 if normilize = 1;
// normalized range is  0 to 1 if normilize = 2;
// no normilization if normilize			= 0;
float	parce_float(char **str, int *fail, int normalize)
{
	float	float_val;

	if (*fail != 0)
		return (0);
	while (**str == ' ')
		*str += 1;
	float_val = parce_float_util(str, fail, normalize);
	if (float_val == 0)
		print_warn("Float is 0!, you might not see anything!\n");
	if (PRINT_DATA)
		printf("%f ", float_val);
	return (float_val);
}

// normalized range is -1 to 1 if normilize = 1;
// normalized range is  0 to 1 if normilize = 2;
// no normilization if normilize			= 0;
t_float_three	parce_float_three(char **str, int *fail, int normalize)
{
	t_float_three	float_three;

	float_three.x = 0;
	if (*fail != 0)
		return (float_three);
	while (**str == ' ')
		*str += 1;
	float_three.x = parce_float_three_util(str, fail, normalize);
	float_three.y = parce_float_three_util(str, fail, normalize);
	float_three.z = parce_float_util(str, fail, normalize);
	if (*fail == 0 && normalize == 1 && float_three.x == 0
		&& float_three.y == 0 && float_three.z == 0)
		print_err_fail("Vector can't be : 0, 0, 0!\n", fail);
	if (PRINT_DATA)
		printf("%f,%f,%f ",
			float_three.x,
			float_three.y,
			float_three.z);
	return (float_three);
}

int	find_str(char **str, int *fail, char *find_str)
{
	if (*fail != 0)
		return (0);
	while (**str == '\n')
		*str += 1;
	if (ft_strlen(*str) < ft_strlen(find_str))
		return (print_err_fail(ERR_INVALID_CHAR, fail));
	if (ft_strncmp(*str, find_str, ft_strlen(find_str)) != 0)
		return (print_err_fail(ERR_INVALID_CHAR, fail));
	*str += ft_strlen(find_str);
	return (0);
}

// this fuction sould be in parce_objects,
// but is in here to conform to norminette.
t_ambient_light	parce_ambient_light(char **str, int *fail)
{
	t_ambient_light	ambient_light;

	ambient_light.intensity = 0;
	if (*fail != 0)
		return (ambient_light);
	find_str(str, fail, "A");
	if (PRINT_DATA)
		printf("A ");
	ambient_light.intensity = parce_float(str, fail, 2);
	ambient_light.col = parce_colour(str, fail);
	if (PRINT_DATA)
		printf("\n");
	if (ambient_light.intensity == 0)
		print_err_fail("Abient ligth may not be 0!\n", fail);
	return (ambient_light);
}
