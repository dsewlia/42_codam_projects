/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:46:51 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/02 12:47:37 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_pa(int *a, int *b, int *data)
{
	int		i;

	i = data[A_COUNT] - 1;
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	i = 0;
	data[A_COUNT]++;
	a[0] = b[0];
	while (i <= data[B_COUNT] - 2)
	{
		b[i] = b[i + 1];
		i++;
	}
	data[B_COUNT]--;
	write (1, "pa\n", 3);
}

void	fn_pb(int *a, int *b, int *data)
{
	int		i;

	i = data[B_COUNT] - 1;
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	i = 0;
	data[B_COUNT]++;
	b[0] = a[0];
	while (i <= data[A_COUNT] - 2)
	{
		a[i] = a[i + 1];
		i++;
	}
	data[A_COUNT]--;
	write (1, "pb\n", 3);
}

void	fn_sa(int *a)
{
	int		temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write (1, "sa\n", 3);
}

void	fn_ra(int *a, int *data)
{
	int		temp;
	int		i;

	temp = a[0];
	i = 0;
	while (i < data[A_COUNT] - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[data[A_COUNT] - 1] = temp;
	write (1, "ra\n", 3);
}

void	fn_rb(int *b, int *data)
{
	int		temp;
	int		i;

	temp = b[0];
	i = 0;
	while (i < data[B_COUNT] - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[data[B_COUNT] - 1] = temp;
	write (1, "rb\n", 3);
}
