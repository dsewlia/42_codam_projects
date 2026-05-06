/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:15:47 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:52:51 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// void	to_uc(unsigned int index, char *ch)
// {
// 	if (*ch >= 'a' && *ch <= 'z' && index >= 0)
// 		*ch = *ch - 32;
// }
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s != NULL || f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// int	main(void)
// {
// 	char	str[] = "Hello world";

// 	printf ("orginal str: %s\n", str);
// 	ft_striteri(str, to_uc);
// 	printf ("Modified str: %s\n", str);
// 	return (0);
// }
