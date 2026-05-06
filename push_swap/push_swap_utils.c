/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:50:42 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/02 18:14:58 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_set_stacks_utils(int *a, int *b, int *data, int *final_index)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (final_index[1] > (data[B_COUNT] - final_index[1]))
		fn_rev_rotate_both(a, b, data, final_index);
	else
	{
		final_index[0] = data[A_COUNT] - final_index[0];
		while (++i < final_index[0])
			fn_rra(a, data);
		while (++j < final_index[1])
			fn_rb(b, data);
	}
}

void	fn_set_stacks(int *a, int *b, int *data, int *final_index)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (final_index[0] <= (data[A_COUNT] - final_index[0]))
	{
		if (final_index[1] <= (data[B_COUNT] - final_index[1]))
			fn_rotate_both(a, b, data, final_index);
		else
		{
			while (++i < final_index[0])
				fn_ra(a, data);
			final_index[1] = data[B_COUNT] - final_index[1];
			while (++j < final_index[1])
				fn_rrb(b, data);
		}
	}
	else
	{
		fn_set_stacks_utils(a, b, data, final_index);
	}
}

void	fn_push_left(int *a, int *b, int *data, int i)
{
	int		min;
	int		steps;
	int		final_index[2];
	int		index_a;

	while (data[B_COUNT] > 0)
	{
		i = -1;
		min = 2147483647;
		while (++i < data[B_COUNT])
		{
			index_a = fn_get_steps_a(a, b, data, i);
			steps = fn_get_steps(index_a, data, i);
			if (steps < min)
			{
				final_index[0] = index_a;
				final_index[1] = i;
				min = steps;
			}
		}
		fn_set_stacks(a, b, data, final_index);
		fn_pa(a, b, data);
	}
	fn_final_phase(a, data);
}

void	fn_push_right(int *a, int *b, int *data)
{
	int		j;
	int		median;

	median = 0;
	while (data[A_COUNT] >= 6)
	{
		median = (data[N] + median) / 2;
		j = -1;
		while (++j <= data[A_COUNT] && data[B_COUNT] < median)
		{
			if (a[0] == 0)
			{
				fn_pb(a, b, data);
				if (data[B_COUNT] > 1)
					fn_rb(b, data);
			}
			else if (a[0] < median)
				fn_pb(a, b, data);
			else
				fn_ra(a, data);
		}
	}
	fn_last_handle(a, b, data, median);
	fn_push_left(a, b, data, 0);
}

void	fn_push_swap(int *a, int *b, int *data, int i)
{
	int		sorted;

	while (++i <= data[N])
	{
		a[i] = b[i];
		b[i] = -1;
	}
	i = -1;
	sorted = 0;
	while (++i < data[A_COUNT] - 1)
	{
		if (a[i] < a[i + 1])
			sorted++;
	}
	if (sorted == data[A_COUNT] - 1)
		return ;
	else if (sorted == 0)
		return (fn_reverse_sorted(data[A_COUNT]));
	else
		fn_push_right(a, b, data);
}
