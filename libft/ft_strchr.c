/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:37:22 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 17:38:27 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	i = 0;
	c = c % 256;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return ((char *)&s1[i]);
		i++;
	}
	if (s1[i] == '\0' && c == '\0')
		return ((char *)&s1[i]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	s[] = "Hello world\n";
// 	char		c;
// 	const char	*str;

// 	c = 't' + 256;
// 	str = strchr(s, c);
// 	printf ("strchr result: %s\n", str);
// 	str = ft_strchr(s, c);
// 	printf ("ft_strchr result: %s\n", str);
// 	return (0);
// }
