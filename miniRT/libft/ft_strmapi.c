/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:45:28 by driemers          #+#    #+#             */
/*   Updated: 2024/10/18 15:51:33 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			string_len;
	char			*string;

	string_len = ft_strlen(s);
	index = 0;
	string = malloc(sizeof(char) * string_len + 1);
	if (string == NULL)
		return (NULL);
	while (s[index] != 0)
	{
		string[index] = f(index, s[index]);
		index++;
	}
	string[index] = 0;
	return (string);
}
