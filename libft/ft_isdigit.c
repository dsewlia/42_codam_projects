/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:29:30 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:51:24 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int		i;

// 	i = isdigit('4');
// 	printf ("isdigit: %d\n", i);
// 	i = ft_isdigit('4');
// 	printf ("ft_isdigit: %d\n", i);
// 	return (0);
// }
