/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:35:36 by driemers          #+#    #+#             */
/*   Updated: 2024/10/23 13:29:45 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (index < n)
	{
		((char *) dest)[index] = ((char *) src)[index];
		index++;
	}
	return (dest);
}
