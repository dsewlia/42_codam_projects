/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:04:19 by driemers          #+#    #+#             */
/*   Updated: 2024/10/23 16:01:33 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s_one;
	unsigned char	*s_two;

	s_one = (unsigned char *)s1;
	s_two = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (s_one[i] != s_two[i])
			return (s_one[i] - s_two[i]);
		i++;
	}
	return (s_one[i] - s_two[i]);
}
