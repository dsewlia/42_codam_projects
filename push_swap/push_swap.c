/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:57:37 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/02 17:34:58 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_check_max(int *a, int *b, int *data)
{
	int		i;

	i = -1;
	while (++i <= data[N])
	{
		if (a[i] == 2147483647)
		{
			b[i] = data[N];
			data[MAX_FLAG] = 1;
		}
	}
}

void	fn_initial_sort(int *a, int *b, int *data, int i)
{
	int		j;
	int		index;
	int		min;

	index = 0;
	fn_check_max(a, b, data);
	while (index <= (data[N] - data[MAX_FLAG]))
	{
		i = -1;
		min = 2147483647;
		while (++i <= data[N])
		{
			if (a[i] < min)
			{
				min = a[i];
				j = i;
			}
		}
		a[j] = 2147483647;
		b[j] = index++;
	}
	fn_push_swap(a, b, data, -1);
}

int	fn_check_dup(int *a, int *data, int i, int j)
{
	data[N] = i - 1;
	data[A_COUNT] = i;
	data[A_MAX] = i - 1;
	data[A_MIN] = 0;
	data[B_MIN] = 2147483647;
	data[B_MAX] = -1;
	data[B_COUNT] = 0;
	data[MAX_FLAG] = 0;
	i = 0;
	while (i <= (data[N] - 1))
	{
		j = i + 1;
		while (j <= data[N])
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	fn_initiate(char **x, int *data, int i, int status)
{
	int		*a;
	int		*b;

	while (x[i] != NULL)
		i++;
	a = (int *)malloc(sizeof(int) * i);
	b = (int *)malloc(sizeof(int) * i);
	if (a == NULL || b == NULL)
		status = 1;
	else
	{
		status = custom_atoi(a, x, data);
		if (status == 0)
			fn_initial_sort(a, b, data, -1);
	}
	if (a != NULL)
		free (a);
	if (b != NULL)
		free (b);
	while (i-- > 0)
		free (x[i]);
	free (x);
	if (status == 1)
		write (STDERR_FILENO, "Error\n", 6);
	return (status);
}

int	main(int argc, char **argv)
{
	int		data[8];
	char	**x;
	int		i;

	i = 0;
	if (argc == 2 && argv[1] != NULL && argv[1][0] != '\0')
		x = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		x = (char **)malloc(sizeof(char *) * argc);
		if (x != NULL)
			x = fn_input_parse(x, argv, argc);
	}
	else
		return (0);
	if (x == NULL)
	{
		write (STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (fn_initiate(x, data, 0, 0));
}
