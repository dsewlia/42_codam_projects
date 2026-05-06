/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:09:09 by driemers          #+#    #+#             */
/*   Updated: 2025/04/17 17:17:45 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	size;
	size_t	index;
	size_t	s_one_size;

	index = 0;
	s_one_size = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = malloc(sizeof(char) * size);
	if (new_string == NULL)
		return (NULL);
	while (s1[s_one_size] != 0)
	{
		new_string[s_one_size] = s1[s_one_size];
		s_one_size++;
	}
	while (s2[index] != 0)
	{
		new_string[s_one_size + index] = s2[index];
		index++;
	}
	new_string[s_one_size + index] = 0;
	return (new_string);
}
