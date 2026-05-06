/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:10:27 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 15:53:29 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		i;
	char	*s;

	a = 0;
	b = 0;
	i = 0;
	while (s1[a] != '\0')
		a++;
	while (s2[b] != '\0')
		b++;
	s = (char *)malloc(sizeof(char) * (a + b) + 1);
	if (s == NULL)
		return (NULL);
	while (i++ < a)
		s[i - 1] = s1[i - 1];
	i--;
	while (i++ < (a + b))
		s[i - 1] = s2[i - a - 1];
	s[i - 1] = '\0';
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	a[] = "Hello-12345678";
// 	const char	b[] = "World123456";
// 	char		*c;

// 	c = ft_strjoin(a, b);
// 	printf("%s\n", c);
// 	return (0);
// }
