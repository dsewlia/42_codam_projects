/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:16:53 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 21:30:13 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;

	len = 0;
	while (s1[len] != '\0')
		len++;
	start = 0;
	while (start < len && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = len;
	while (end > 0 && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	return (ft_substr(s1, start, end - start));
}
