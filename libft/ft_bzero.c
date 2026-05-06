/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:38:40 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:51:00 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <strings.h>
// #include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	unsigned char	*p1;
	unsigned long	n1;

	p1 = (unsigned char *) s;
	i = 0;
	n1 = n;
	while (i < n1)
	{
		p1[i] = (unsigned char) 0;
		i++;
	}
}

// int	main(void)
// {
// 	char	s[] = "abcd";
// 	char	s1[] = "abcd";
// 	int		i = 0;

// 	bzero(s, 2);
// 	ft_bzero(s1, 2);
// 	printf("bzero: ");
// 	while (i++ < 4)
// 		printf("%c", s[i - 1]);
// 	printf("\n ft_bzero: ");
// 	i = 0;
// 	while (i++ < 4)
// 		printf("%c", s1[i - 1]);
// 	printf ("\n");
// 	return (0);
// }
