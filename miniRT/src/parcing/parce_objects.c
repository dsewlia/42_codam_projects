/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:36:01 by driemers          #+#    #+#             */
/*   Updated: 2025/05/05 13:17:49 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>
#include <stdio.h>

// theze functions call the correct order of,
// parcing fuctions for each object type.

// parce_ambient_light is in parce_utils to conform to norminette.

t_camera	parce_cam(char **str, int *fail)
{
	t_camera	camera;

	camera.fov = 0;
	if (*fail != 0)
		return (camera);
	find_str(str, fail, "C");
	if (PRINT_DATA)
		printf("C ");
	camera.pos = parce_float_three(str, fail, 0);
	camera.rot = parce_float_three(str, fail, 1);
	camera.fov = parce_float(str, fail, 0);
	if (PRINT_DATA)
		printf("\n");
	if ((camera.fov < 0 || camera.fov > 180) && *fail == 0)
	{
		print_err("camera fov is outside of bounds!\n");
		*fail = 1;
	}
	return (camera);
}

t_light	*parce_light(char **str, int *fail)
{
	t_light	*light;

	if (*fail != 0)
		return (NULL);
	light = malloc(sizeof(t_light));
	if (light == NULL)
		return (print_err_fail_null(ERR_MEM_FAIL, fail));
	light->next = NULL;
	find_str(str, fail, "L");
	if (PRINT_DATA)
		printf("L ");
	light->pos = parce_float_three(str, fail, 0);
	light->intensity = parce_float(str, fail, 2);
	light->col = parce_colour(str, fail);
	if (PRINT_DATA)
		printf("\n");
	return (light);
}

t_sphere	*parce_sphere(char **str, int *fail)
{
	t_sphere	*sphere;

	if (*fail != 0)
		return (NULL);
	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (print_err_fail_null(ERR_MEM_FAIL, fail));
	sphere->next = NULL;
	find_str(str, fail, "sp");
	if (PRINT_DATA)
		printf("sp ");
	sphere->pos = parce_float_three(str, fail, 0);
	sphere->diameter = parce_float(str, fail, 0);
	if (sphere->diameter < 0)
		print_err_fail(ERR_VALUE_NEGATIVE, fail);
	sphere->col = parce_colour(str, fail);
	if (PRINT_DATA)
		printf("\n");
	return (sphere);
}

t_plane	*parce_plane(char **str, int *fail)
{
	t_plane	*plane;

	if (*fail != 0)
		return (NULL);
	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		return (print_err_fail_null(ERR_MEM_FAIL, fail));
	plane->next = NULL;
	find_str(str, fail, "pl");
	if (PRINT_DATA)
		printf("pl ");
	plane->pos = parce_float_three(str, fail, 0);
	plane->normal = parce_float_three(str, fail, 1);
	plane->col = parce_colour(str, fail);
	if (PRINT_DATA)
		printf("\n");
	return (plane);
}

t_cylinder	*parce_cylinder(char **str, int *fail)
{
	t_cylinder	*cylinder;

	if (*fail != 0)
		return (NULL);
	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (print_err_fail_null(ERR_MEM_FAIL, fail));
	cylinder->next = NULL;
	find_str(str, fail, "cy");
	if (PRINT_DATA)
		printf("cy ");
	cylinder->pos = parce_float_three(str, fail, 0);
	cylinder->rot = parce_float_three(str, fail, 1);
	cylinder->diameter = parce_float(str, fail, 0);
	if (cylinder->diameter < 0)
		print_err_fail(ERR_VALUE_NEGATIVE, fail);
	cylinder->height = parce_float(str, fail, 0);
	if (cylinder->height < 0)
		print_err_fail(ERR_VALUE_NEGATIVE, fail);
	cylinder->col = parce_colour(str, fail);
	if (PRINT_DATA)
		printf("\n");
	return (cylinder);
}
