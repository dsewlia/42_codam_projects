/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:55:01 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 20:31:15 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	d = (unsigned char *) dest;
	s = (unsigned const char *) src;
	if (s < d)
		while (n-- > 0)
			d[n] = s[n];
	else
		while (i++ < n)
			d[i - 1] = s[i - 1];
	return (dest);
}

// int	main(void)
// {
// 	char	testdsys[] = "Hello World";
// 	char	testssys[] = "12345";
// 	char	testdft[] = "Hello World";
// 	char	testsft[] = "12345";
// 	void	*a_sys;
// 	void	*a_ft;

// 	a_sys = memmove(testdsys, testssys, 15);
// 	a_ft = ft_memmove(testdft, testsft, 15);
// 	printf ("memcpy result: %s\n", (char *)a_sys);
// 	printf ("ft_memcpy result: %s\n", (char *)a_ft);
// 	return (0);
// }
