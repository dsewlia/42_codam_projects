/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_cal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:53:49 by dsewlia           #+#    #+#             */
/*   Updated: 2024/12/30 22:54:14 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fn_get_steps_a(int *a, int *b, int *data, int x)
{
	int		i;
	int		j;

	i = 0;
	while (a[i] != data[N])
		i++;
	if (i == (data[A_COUNT] - 1))
		i = -1;
	j = i;
	while (++i <= (data[A_COUNT] - 1))
	{
		if (a[i] > b[x])
			return (i);
	}
	i = -1;
	while (++i <= j)
	{
		if (a[i] > b[x])
			return (i);
	}
	return (0);
}

void	fn_final_phase(int *a, int *data)
{
	int		i;
	int		j;

	i = 0;
	while (a[i] != 0)
		i++;
	j = data[A_COUNT] - i;
	if (i <= j)
	{
		while (i > 0)
		{
			fn_ra(a, data);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			fn_rra(a, data);
			j--;
		}
	}
}

int	fn_get_steps(int index_a, int *data, int i)
{
	if (index_a <= data[A_COUNT] - index_a)
	{
		if (i <= data[B_COUNT] - i)
		{
			if (index_a >= i)
				return (index_a);
			else
				return (i);
		}
		else
			return (index_a + data[B_COUNT] - i);
	}
	else
	{
		if (i <= data[B_COUNT] - i)
			return (data[A_COUNT] - index_a + i);
		else
		{
			if (data[A_COUNT] - index_a >= data[B_COUNT] - i)
				return (data[A_COUNT] - index_a);
			else
				return (data[B_COUNT] - i);
		}
	}
}

void	fn_rotate_both(int *a, int *b, int *data, int *final_index)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < final_index[0] && j < final_index[1])
	{
		fn_rr(a, b, data);
		i++;
		j++;
	}
	while (i < final_index[0])
	{
		fn_ra(a, data);
		i++;
	}
	while (j < final_index[1])
	{
		fn_rb(b, data);
		j++;
	}
}

void	fn_rev_rotate_both(int *a, int *b, int *data, int *final_index)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	final_index[0] = data[A_COUNT] - final_index[0];
	final_index[1] = data[B_COUNT] - final_index[1];
	while (i < final_index[0] && j < final_index[1])
	{
		fn_rrr(a, b, data);
		i++;
		j++;
	}
	while (i < final_index[0])
	{
		fn_rra(a, data);
		i++;
	}
	while (j < final_index[1])
	{
		fn_rrb(b, data);
		j++;
	}
}
