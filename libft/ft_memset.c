/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:21:13 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:51:54 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*p1;

	p1 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		p1[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	s[4];
// 	char	s1[4];

// 	s[3] = '\0';
// 	s1[3] = '\0';
// 	memset(s, 48, 3);
// 	ft_memset(s1, 48, 3);
// 	printf("memset: %s\n", s);
// 	printf("ft_memset: %s\n", s1);
// 	return (0);
// }
