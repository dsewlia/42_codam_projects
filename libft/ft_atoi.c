/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:06:07 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:50:55 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num(const char *nptr, int i, int a)
{
	int		x;
	int		y;
	int		num;

	num = 0;
	while (a > 0)
	{
		x = a;
		y = 1;
		while (x > 1)
		{
			y = y * 10;
			x--;
		}
		num = num + ((nptr[i - a] - '0') * y);
		a--;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		a;
	int		sign;

	i = 0;
	sign = 1;
	a = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i + a] >= '0' && nptr[i + a] <= '9')
		a++;
	if (a == 0)
		return (0);
	return (sign * get_num(nptr, i + a, a));
}

// #include <stdlib.h>
// #include <stdio.h>

// int	main(void)
// {
// 	// char	s[] = "+00001mnanm";
// 	char *s;

// 	s = NULL;
// 	printf ("atoi: %d\n", atoi(s));
// 	printf ("ft_atoi: %d\n", ft_atoi(s));
// 	return (0);
// }
