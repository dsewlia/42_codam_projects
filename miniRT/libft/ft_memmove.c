/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:03:06 by driemers          #+#    #+#             */
/*   Updated: 2024/10/23 13:39:28 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		index = n;
		while (index > 0)
		{
			index--;
			((char *) dest)[index] = ((char *) src)[index];
		}
	}
	else
	{
		dest = ft_memcpy(dest, src, n);
	}
	return (dest);
}
