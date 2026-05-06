/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:15:57 by driemers          #+#    #+#             */
/*   Updated: 2024/10/15 15:21:16 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*new_pointer;

	new_pointer = (char *) s;
	while (*new_pointer != (char) c && *new_pointer != 0)
		new_pointer++;
	if (*new_pointer == (char) c)
		return (new_pointer);
	return (NULL);
}
