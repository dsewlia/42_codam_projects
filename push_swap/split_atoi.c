/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:48:40 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/02 14:08:44 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_split_array(char **a, char const *s, char c)
{
	int		i;
	int		j;
	int		x;

	j = 0;
	x = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		i = 0;
		while (s[x] != '\0' && s[x] != c)
		{
			a[j][i] = s[x];
			i++;
			x++;
		}
		if (i > 0)
		{
			a[j][i] = '\0';
			j++;
		}
	}
	a[j] = NULL;
	return (a);
}

char	**get_array_mem(char **a, char const *s, char c, int x)
{
	int		i;
	int		j;

	j = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		i = 0;
		while (s[x] != '\0' && s[x] != c)
		{
			i++;
			x++;
		}
		if (i > 0)
		{
			a[j] = (char *)malloc(sizeof(char) * i + 1);
			if (a[j] == NULL)
				return (NULL);
		}
		j++;
	}
	return (get_split_array(a, s, c));
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		x;
	int		count;

	if (s == NULL)
		return (NULL);
	count = 0;
	x = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0' && s[x] != c)
		{
			count++;
			while (s[x] != '\0' && s[x] != c)
				x++;
		}
	}
	a = (char **)malloc(sizeof(char *) * (count + 1));
	if (a == NULL)
		return (NULL);
	return (get_array_mem(a, s, c, 0));
}

long int	custom_atoi_2(char *c, long int th, long int num, int i)
{
	while (c[i] != '\0')
	{
		th = th * 10;
		i++;
	}
	i = 0;
	while (c[i] != '\0')
	{
		th = th / 10;
		num = num + ((c[i] - '0') * th);
		i++;
	}
	return (num);
}

int	custom_atoi(int *a, char **x, int *data)
{
	int			i;
	int			j;
	long int	num;
	int			sign;

	i = 0;
	while (x[i] != NULL)
	{
		j = -1;
		sign = 0;
		if (x[i][0] == '-' || x[i][0] == '+')
			sign = 1;
		while (x[i][++j + sign] != '\0')
			if (x[i][j + sign] < '0' || x[i][j + sign] > '9')
				return (1);
		num = custom_atoi_2(&x[i][sign], 1, 0, 0);
		if (sign == 1 && x[i][0] == '-')
			num = num * -1;
		if (num < -2147483648 || num > 2147483647 || (num == 0 && sign == 1))
			return (1);
		a[i] = num;
		i++;
	}
	return (fn_check_dup(a, data, i, 0));
}
