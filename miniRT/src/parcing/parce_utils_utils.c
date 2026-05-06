/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_utils_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:34:36 by driemers          #+#    #+#             */
/*   Updated: 2025/04/29 14:49:57 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../../libft/libft.h"
#include <math.h>
#include <stdio.h>

unsigned char	parce_uint_eightbit(char **str, int *fail, int last)
{
	int	uint_eightbit;
	int	index;

	index = 0;
	if (*fail != 0)
		return (0);
	if (**str == '+')
		index++;
	if (ft_isdigit(str[0][index]) == 0)
		return (print_err_fail(ERR_INVALID_CHAR, fail));
	if (str[0][index] == '0' && ft_isdigit(str[0][index + 1]) != 0)
		return (print_err_fail(ERR_INVALID_CHAR, fail));
	while (ft_isdigit(str[0][index]) != 0)
	{
		if (index >= 4)
			return (print_err_fail(ERR_CHAR_OUT_OF_BOUNDS, fail));
		index++;
	}
	uint_eightbit = ft_atoi(*str);
	if (uint_eightbit > 255 || uint_eightbit < 0)
		return (print_err_fail(ERR_CHAR_OUT_OF_BOUNDS, fail));
	*str += index;
	if (**str == ',' && last == 0)
		*str += 1;
	return (uint_eightbit);
}

static float	pfu_retval(char **str, int *fail, int normalize, int index)
{
	float	float_val;

	if (str[0][0] == '0' && ft_isdigit(str[0][1]) != 0)
		return (print_err_fail(ERR_INVALID_CHAR, fail));
	float_val = rt_atof(*str, index, fail);
	*str += index;
	if (*fail == 0 && normalize == 1
		&& (isgreater(float_val, 1) || isless(float_val, -1)))
		return (print_err_fail(ERR_FLOAT_N_OUTSIDE_BOUNDS, fail));
	if (*fail == 0 && normalize == 2
		&& (isgreater(float_val, 1) || isless(float_val, 0)))
		return (print_err_fail(ERR_FLOAT_N_OUTSIDE_BOUNDS, fail));
	return (float_val);
}

float	parce_float_util(char **str, int *fail, int normalize)
{
	int		decimal;
	int		index;

	index = 1;
	decimal = 0;
	if (*fail != 0)
		return (0);
	if (ft_isdigit(**str) == 0 && **str != '-' && **str != '+' && **str != '.')
		return (print_err_fail(ERR_INVALID_CHAR, fail));
	if (**str == '.')
		decimal++;
	while (str[0][index] != 0)
	{
		if (str[0][index] == '.' && decimal != 0)
			return (print_err_fail(ERR_INVALID_CHAR, fail));
		if (str[0][index] == '.')
			decimal++;
		if (ft_isdigit(str[0][index]) == 0 && str[0][index] != '.')
			break ;
		index++;
	}
	return (pfu_retval(str, fail, normalize, index));
}

float	parce_float_three_util(char **str, int *fail, int normalize)
{
	float	float_one;

	if (*fail != 0)
		return (0);
	float_one = parce_float_util(str, fail, normalize);
	if (*fail != 0)
		return (float_one);
	if (**str != ',')
		return ((float)print_err_fail(ERR_INVALID_CHAR, fail));
	*str += 1;
	return (float_one);
}

void	clear_str(char *str, int size)
{
	while (size >= 0)
	{
		str[size] = 0;
		size--;
	}
}
