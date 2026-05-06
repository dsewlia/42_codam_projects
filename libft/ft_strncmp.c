/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:03:53 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 15:24:59 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main function and call to stdio library in comments
//#include <stdio.h>
#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (((ss1[i] != '\0') || (ss2[i] != '\0')) && i < n)
	{
		if (ss1[i] > ss2[i])
			return (1);
		else if (ss1[i] < ss2[i])
			return (-1);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*a;
// 	char	*b;

// 	a = "abc";
// 	b = "accd";
// 	printf("strncmp result: %d", ft_strncmp(a, b, 3));
// 	return (0);
// }
