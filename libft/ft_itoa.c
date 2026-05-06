/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:51:57 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 19:33:14 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include "libft.h"

char	*get_itoa(long int n1, long int a, long int sign)
{
	char	*num;

	if (n1 == 0)
	{
		num = (char *)malloc(sizeof(char) * 2);
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	num = (char *)malloc(sizeof(char) * (a + sign) + 1);
	if (num == NULL)
		return (NULL);
	num[a + sign] = '\0';
	if (sign == 1)
		num[0] = '-';
	while (n1 != 0)
	{
		num[a + sign - 1] = (n1 % 10) + '0';
		n1 = n1 / 10;
		a--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	long int	n1;
	long int	sign;
	long int	a;
	long int	n2;

	n1 = n;
	a = 0;
	sign = 0;
	if (n1 < 0)
	{
		sign = 1;
		n1 = -n1;
	}
	n2 = n1;
	while (n2 != 0)
	{
		n2 = n2 / 10;
		a++;
	}
	return (get_itoa(n1, a, sign));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		n;
// 	char	*a;

// 	n = 0;
// 	a = ft_itoa(n);
// 	printf ("%s\n", a);
// 	return (0);
// }
