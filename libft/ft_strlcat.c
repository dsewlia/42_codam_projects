/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:10:56 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:53:00 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main function and call to stdio library in comments
//#include <stdio.h>
#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	a;

	i = 0;
	j = 0;
	a = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (size == 0 || size <= i)
		return (j + size);
	while ((src[a] != '\0') && (a < (size - i - 1)))
	{
		dest[i + a] = src[a];
		a++;
	}
	dest[i + a] = '\0';
	return (i + j);
}

// int	main(void)
// {
// 	char				a[] = "abcd\n";
// 	char				b[] = "xyz\n";
// 	unsigned int		i;
// 	printf("The initial value of dest: %s\n", a);
// 	printf("The initial value of src: %s\n", b);
// 	i = ft_strlcat(a, b, 2);
// 	printf("The final value of dest: %s\n", a);
// 	printf("The final value of src: %s\n", b);
// 	printf("The size is: %d\n", i);
// 	return (0);
// }
