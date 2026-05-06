/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:36:39 by driemers          #+#    #+#             */
/*   Updated: 2024/10/23 15:20:25 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new_pointer;

	new_pointer = (char *) s + ft_strlen(s);
	while (*new_pointer != (char) c && new_pointer > s)
		new_pointer--;
	if (*new_pointer == (char) c)
		return (new_pointer);
	return (NULL);
}
