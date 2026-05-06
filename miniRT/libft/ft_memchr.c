/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:53:24 by driemers          #+#    #+#             */
/*   Updated: 2024/10/23 15:49:11 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	void	*return_pointer;

	return_pointer = (void *)s;
	index = 0;
	if (n == 0)
		return (NULL);
	n--;
	while (index < n && *((unsigned char *)return_pointer) != (unsigned char) c)
	{
		index++;
		return_pointer++;
	}
	if (*((unsigned char *)return_pointer) == (unsigned char) c)
		return (return_pointer);
	return (NULL);
}
