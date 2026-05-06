/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:33:30 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:54:02 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

// int	main(void)
// {
// 	char	a = 'x';

// 	printf ("toupper: %c\n", toupper(a));
// 	printf ("ft_toupper: %c\n", ft_toupper(a));
// 	return (0);
// }
