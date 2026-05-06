/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:29:11 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 20:14:35 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen1(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		src_size;
	char	*dest;
	int		i;

	src_size = ft_strlen1(src);
	dest = (char *)malloc(sizeof(char) * src_size + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i <= src_size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
