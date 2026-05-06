/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:35:12 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:53:57 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

// int	main(void)
// {
// 	char	a = 'X';

// 	printf ("toupper: %c\n", tolower(a));
// 	printf ("ft_toupper: %c\n", ft_tolower(a));
// 	return (0);
// }
