/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:38:41 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 21:31:04 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*complete program in comments and there is a doubt*/
// #include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	int		a;
// 	char	*s;

// 	s = NULL;
// 	a = ft_strlen(s);
// 	printf("The length of the string is: %d", a);
// 	return (0);
// }
