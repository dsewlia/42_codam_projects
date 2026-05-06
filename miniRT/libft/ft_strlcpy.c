/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:19:07 by driemers          #+#    #+#             */
/*   Updated: 2024/10/16 18:00:32 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	int		found_null_byte;

	found_null_byte = 0;
	index = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (index < size - 1 && !found_null_byte)
	{
		dst[index] = src[index];
		if (src[index] == 0)
			found_null_byte = 1;
		else
			index++;
	}
	dst[index] = 0;
	return (ft_strlen(src));
}
