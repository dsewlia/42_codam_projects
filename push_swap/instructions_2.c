/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:47:29 by dsewlia           #+#    #+#             */
/*   Updated: 2024/12/30 22:47:46 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_rr(int *a, int *b, int *data)
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
	temp = b[0];
	i = 0;
	while (i < data[B_COUNT] - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[data[B_COUNT] - 1] = temp;
	write (1, "rr\n", 3);
}

void	fn_rra(int *a, int *data)
{
	int		temp;
	int		i;

	temp = a[data[A_COUNT] - 1];
	i = data[A_COUNT] - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	write (1, "rra\n", 4);
}

void	fn_rrb(int *b, int *data)
{
	int		temp;
	int		i;

	temp = b[data[B_COUNT] - 1];
	i = data[B_COUNT] - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write (1, "rrb\n", 4);
}

void	fn_rrr(int *a, int *b, int *data)
{
	int		temp;
	int		i;

	temp = a[data[A_COUNT] - 1];
	i = data[A_COUNT] - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	temp = b[data[B_COUNT] - 1];
	i = data[B_COUNT] - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write (1, "rrr\n", 4);
}
