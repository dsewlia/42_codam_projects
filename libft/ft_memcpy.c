/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:41:52 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 20:28:55 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	unsigned const char		*s;
	size_t					i;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (unsigned char *) dest;
	s = (unsigned const char *) src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	testdsys[] = "Hello World";
// 	char	testssys[] = "123456789012345";
// 	char	testdft[] = "Hello World";
// 	char	testsft[] = "123456789012345";
// 	void	*a_sys;
// 	void	*a_ft;

// 	a_sys = memcpy(testdsys, testssys, 15);
// 	a_ft = ft_memcpy(testdft, testsft, 15);
// 	printf ("memcpy result: %s\n", (char *)a_sys);
// 	printf ("ft_memcpy result: %s\n", (char *)a_ft);
// 	return (0);
// }
