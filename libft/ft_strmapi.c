/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:06:01 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:53:25 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
#include "libft.h"

// char	to_uc(unsigned int index, char ch)
// {
// 	if (ch >= 'a' && ch <= 'z' && index >= 0)
// 		ch = ch - 32;
// 	return (ch);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	s1 = (char *)malloc(sizeof(char) * i + 1);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// int	main(void)
// {
// 	char	str[] = "Hello world";
// 	char	*str1;

// 	printf ("orginal str: %s\n", str);
// 	str1 = ft_strmapi(str, to_uc);
// 	printf ("Modified str: %s\n", str);
// 	return (0);
// }
