/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:55:58 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 20:24:06 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	i = 0;
	c1 = c;
	if (n == 0)
		return (NULL);
	s1 = (unsigned char *)s;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	s[] = "Hello world\n";
// 	char		c;
// 	const char	*str;

// 	c = 'l';
// 	str = memchr(s, c, 8);
// 	printf ("memchr result: %s\n", str);
// 	str = ft_memchr(s, c, 8);
// 	printf ("ft_memchr result: %s\n", str);
// 	return (0);
// }
