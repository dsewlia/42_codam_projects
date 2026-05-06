/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:40:04 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 17:44:19 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*s1;

	i = 0;
	c = c % 256;
	s1 = (unsigned char *)s;
	while (s1[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)&s1[i]);
	while (i > 0)
	{
		if (s[i - 1] == c)
			return ((char *)&s1[i - 1]);
		i--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	s[] = "Hello world\n";
// 	char		c;
// 	char		*str;

// 	c = '\0';
// 	str = strrchr(s, c);
// 	printf ("strrchr result: %s\n", str);
// 	str = ft_strrchr(s, c);
// 	printf ("ft_strrchr result: %s\n", str);
// 	return (0);
// }
