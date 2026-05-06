/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:19:01 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:53:04 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main function and call to stdio library in comments
//#include <stdio.h>
#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while ((i < size - 1) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	char			dest[] = "12345678";
// 	char			src[] = "1234";
// 	unsigned int	i;
// 	unsigned int	src_size;

// 	i = 2;
// 	src_size = ft_strlcpy(dest, src, i);
// 	printf("dest: %s\n", dest);
// 	printf("src: %s\n", src);
// 	printf("size of source: %d\n", src_size);
// 	return (0);
// }