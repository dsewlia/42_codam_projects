/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:42:33 by driemers          #+#    #+#             */
/*   Updated: 2024/10/25 13:01:59 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	size_t			total_size;
	size_t			index;

	total_size = nmemb * size;
	if (total_size != 0 && total_size / size != nmemb)
		return (NULL);
	index = 0;
	mem = malloc(total_size);
	if (mem == NULL)
		return (NULL);
	while (index < total_size)
	{
		mem[index] = 0;
		index++;
	}
	return ((void *) mem);
}
