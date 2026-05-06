/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:39:10 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 20:11:32 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	long int		n1;
	long int		n2;
	long int		n3;
	unsigned char	*a;
	int				i;

	n1 = nmemb;
	n2 = size;
	n3 = n1 * n2;
	if (nmemb <= 0 || size <= 0)
		return (malloc(1));
	if (n3 > 2147483647)
		return (NULL);
	a = (unsigned char *)malloc(n3);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < n3)
	{
		a[i] = 0;
		i++;
	}
	return ((void *)a);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	// void			*a;
// 	// void			*b;
// 	long int		ai;
// 	long int		bi;
// 	unsigned char	*ac;
// 	unsigned char	*bc;

// 	ac = (unsigned char *)calloc(21, 5);
// 	bc = (unsigned char *)ft_calloc(21, 5);
// 	// ac = (unsigned char *)a;
// 	// bc = (unsigned char *)b;
// 	ai = 0;
// 	bi = 0;
// 	while (ac[ai] == 0 && ai < 21)
// 		ai++;
// 	while (bc[bi] == 0 && bi < 21)
// 		bi++;
// 	printf ("calloc size: %ld\n", ai);
// 	printf ("ft calloc size: %ld\n", bi);
// 	return (0);
// }
