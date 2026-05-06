/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:44:13 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:51:40 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*ss1;
	unsigned const char	*ss2;
	size_t				i;

	i = 0;
	ss1 = (unsigned const char *) s1;
	ss2 = (unsigned const char *) s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	tests1[] = "hello World";
// 	char	tests2[] = "hello World";

// 	printf ("memcmp result: %d\n", memcmp(tests1, tests2, 0));
// 	printf ("ft_memcmp result: %d\n", ft_memcmp(tests1, tests2, 0));
// 	return (0);
// }
