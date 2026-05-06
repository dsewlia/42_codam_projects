/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:12:46 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:51:15 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int		i;

// 	i = isalpha(4);
// 	printf ("isalpha: %d\n", i);
// 	i = ft_isalpha(4);
// 	printf ("ft_isalpha: %d\n", i);
// 	return (0);
// }
