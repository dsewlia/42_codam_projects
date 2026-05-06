/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:26:35 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 20:35:14 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <bsd/string.h>
// #include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		x;

	i = 0;
	x = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (little[x] != '\0')
		x++;
	while (big[i] != '\0' && i < (len - x + 1))
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] != '\0' && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	b[] = "Hello world";
// 	char	l[] = "world";
// 	char	*s_sys;
// 	char	*s_ft;

// 	s_sys = strnstr(b, l, 11);
// 	s_ft = ft_strnstr(b, l, 11);
// 	printf ("strnstr result: %s\n", s_sys);
// 	printf ("ft_strnstr result: %s\n", s_ft);
// 	return (0);
// }
