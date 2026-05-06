/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:24:12 by driemers          #+#    #+#             */
/*   Updated: 2024/10/18 17:17:07 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		index;
	int		size;

	size = ft_strlen(s);
	index = 0;
	new_string = malloc(sizeof(char) * (size + 1));
	if (new_string == NULL)
		return (NULL);
	while (index < size)
	{
		new_string[index] = ((char *) s)[index];
		index++;
	}
	new_string[index] = 0;
	return (new_string);
}
