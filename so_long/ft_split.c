/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:05:51 by dsewlia           #+#    #+#             */
/*   Updated: 2025/02/21 12:33:12 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include "so_long.h"

char	**get_split_array(char **a, char const *s, char c)
{
	int		i;
	int		j;
	int		x;

	j = 0;
	x = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		i = 0;
		while (s[x] != '\0' && s[x] != c)
		{
			a[j][i] = s[x];
			i++;
			x++;
		}
		if (i > 0)
		{
			a[j][i] = '\0';
			j++;
		}
	}
	a[j] = NULL;
	return (a);
}

char	**get_array_mem(char **a, char const *s, char c, int x)
{
	int		i;
	int		j;

	j = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		i = 0;
		while (s[x] != '\0' && s[x] != c)
		{
			i++;
			x++;
		}
		if (i > 0)
		{
			a[j] = (char *)ft_calloc(sizeof(char), i + 1);
			if (a[j] == NULL)
				return (NULL);
		}
		j++;
	}
	return (get_split_array(a, s, c));
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		x;
	int		count;

	if (s == NULL)
		return (NULL);
	count = 0;
	x = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0' && s[x] != c)
		{
			count++;
			while (s[x] != '\0' && s[x] != c)
				x++;
		}
	}
	a = (char **)ft_calloc(sizeof(char *), (count + 1));
	if (a == NULL)
		return (NULL);
	return (get_array_mem(a, s, c, 0));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	a[] = "11He1llo-1world :1Okay!11";
// 	char	c = '1';
// 	char	**b;
// 	int		i;

// 	b = ft_split(a, c);
// 	i = 0;
// 	while (b[i] != NULL)
// 	{
// 		printf ("%s\n", b[i]);
// 		i++;
// 	}
// 	return (0);
// }
