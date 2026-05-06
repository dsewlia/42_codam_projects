/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:28:37 by driemers          #+#    #+#             */
/*   Updated: 2024/10/25 13:00:14 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static char	*test_fit(size_t big_index, const char *big, const char *little)
{
	size_t	little_index;
	int		foundfault;

	little_index = 0;
	foundfault = 0;
	if (big[big_index] == *little)
	{
		while (little[little_index] != 0 && !foundfault)
		{
			if (!(little[little_index] == big[big_index + little_index]))
				foundfault = 1;
			little_index++;
		}
		if (!foundfault)
			return ((char *)big + big_index);
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t	little_len;
	size_t	big_len;

	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	big_index = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big_index + little_len <= len && big_index <= big_len)
	{
		if (test_fit(big_index, big, little))
			return (test_fit(big_index, big, little));
		big_index++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	printf("%s\n", ft_strnstr("fff" ,"sss" ,0));
// 	//printf("%s\n", strnstr("" ,"" ,0));
// }
