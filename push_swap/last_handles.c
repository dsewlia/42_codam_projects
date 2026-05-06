/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_handles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:52:24 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/02 18:11:49 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_reverse_sorted(int n)
{
	int		i;

	i = 0;
	if (n == 2)
	{
		write (1, "sa\n", 3);
		return ;
	}
	while (i < n - 3)
	{
		write (1, "pb\n", 3);
		i++;
	}
	write (1, "ra\n", 3);
	write (1, "sa\n", 3);
	while (i > 0)
	{
		write (1, "pa\nra\n", 6);
		i--;
	}
}

void	fn_sort_three(int *a, int *data, int median)
{
	if (a[0] == median)
	{
		if (a[1] == data[N])
		{
			fn_sa(a);
			fn_ra(a, data);
		}
	}
	else if (a[0] == data[N])
	{
		if (a[1] == median)
			fn_ra(a, data);
		else
		{
			fn_ra(a, data);
			fn_sa(a);
		}
	}
	else
	{
		if (a[1] == median)
			fn_sa(a);
		else
			fn_rra(a, data);
	}
}

void	fn_last_handle(int *a, int *b, int *data, int median)
{
	median = data[N] - 2;
	while (data[A_COUNT] > 3)
	{
		if (a[0] < median)
			fn_pb(a, b, data);
		else
			fn_ra(a, data);
	}
	fn_sort_three(a, data, median);
}

char	*fn_argv_copy(char *a)
{
	char	*str;
	size_t	n;

	n = 0;
	while (a[n] != '\0')
		n++;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	n = 0;
	while (a[n] != '\0')
	{
		str[n] = a[n];
		n++;
	}
	str[n] = '\0';
	return (str);
}
