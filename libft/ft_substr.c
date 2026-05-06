/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:06:22 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 20:00:07 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	x;
	char	*a;
	char	*b;

	i = 0;
	x = 0;
	while (s[i] != '\0')
		i++;
	if (start >= i || len == 0)
	{
		b = (char *)malloc(sizeof(char) * 1);
		b[0] = '\0';
		return (b);
	}
	i = 0;
	while (s[start + i] != '\0' && i < len)
		i++;
	a = (char *)malloc(sizeof(char) * (i + 1));
	if (a == NULL)
		return (NULL);
	while (x++ < i)
		a[x - 1] = s[x + start -1];
	a[x - 1] = '\0';
	return (a);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	a[] = "tripouille";
// 	char	*b;

// 	b = ft_substr(a, 100, 1);
// 	printf ("%s\n", b);
// 	return (0);
// }
