/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:49:00 by driemers          #+#    #+#             */
/*   Updated: 2024/10/24 12:41:30 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	index;
	size_t	s_len;

	index = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		start = s_len;
	if (len > s_len - start)
		len = s_len - start;
	new_string = malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		return (NULL);
	if (start < s_len)
	{
		while (index < len && s[index + start] != 0)
		{
			new_string[index] = ((char *) s)[index + start];
			index++;
		}
	}
	new_string[index] = 0;
	return (new_string);
}
