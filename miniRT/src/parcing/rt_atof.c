/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:50:35 by driemers          #+#    #+#             */
/*   Updated: 2025/05/02 13:45:27 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <math.h>

static int	test_val(char *str, int intval, int n, int *fail)
{
	char	*itoa_str;

	itoa_str = ft_itoa(intval);
	if (itoa_str == NULL)
		return (print_err_fail(ERR_MEM_FAIL, fail));
	if (DEBUG)
		printf("\nITOA: %s\nNUM: %i\nSTR: %s\n INDEX: %i\n",
			itoa_str, intval, str, n);
	if (ft_strncmp(str, itoa_str, n) != 0)
	{
		free (itoa_str);
		return (print_err_fail(ERR_FLOAT_OUTSIDE_BOUNDS, fail));
	}
	free (itoa_str);
	return (1);
}

static int	set_desimal(char *str, int n, int *desimal)
{
	int	index;

	index = n;
	*desimal = 0;
	while (index > 0)
	{
		index--;
		if (str[index] == '.')
			return (index);
		*desimal = 1;
	}
	*desimal = 0;
	return (n);
}

static float	get_des(char *str)
{
	int		index;
	float	ret_val;

	ret_val = 0;
	index = 0;
	while (ft_isdigit(str[index]) != 0 && index < 10)
	{
		ret_val += (float)(str[index] - '0') / pow(10, index + 1);
		index++;
	}
	if (DEBUG)
		printf("DES_VAL: %f\n", ret_val);
	return (ret_val);
}

float	rt_atof(char *str, int n, int *fail)
{
	int		desimal;
	int		index;
	int		intval;
	float	desval;

	if (*fail != 0)
		return (0);
	desval = 0;
	index = set_desimal(str, n, &desimal);
	intval = ft_atoi(str);
	if (desimal != 0)
		desval = get_des(str + index + 1);
	if (index >= 3 && test_val(str, intval, index, fail) == 0)
		return (0);
	if (*str == '-')
		return ((float)intval - desval);
	return ((float)intval + desval);
}
