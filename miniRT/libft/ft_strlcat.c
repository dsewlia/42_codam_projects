/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:41:26 by driemers          #+#    #+#             */
/*   Updated: 2024/10/23 15:12:05 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index = 0;
	if (dst_len >= size)
		return (size + src_len);
	while (src[index] != 0 && (dst_len + index) < (size -1))
	{
		dst[index + dst_len] = src[index];
		index++;
	}
	dst[dst_len + index] = 0;
	return (dst_len + src_len);
}
