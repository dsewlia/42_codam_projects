/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:26:32 by driemers          #+#    #+#             */
/*   Updated: 2024/10/16 17:41:54 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front_trim;
	size_t	back_trim;
	size_t	string_len;
	int		found_differance;

	found_differance = 0;
	back_trim = ft_strlen(s1);
	string_len = back_trim;
	front_trim = 0;
	while (s1[front_trim] != 0 && !found_differance)
	{
		if (!ft_strchr(set, s1[front_trim]))
			found_differance = 1;
		else
			front_trim++;
	}
	found_differance = 0;
	while (back_trim > 0 && !found_differance && front_trim < back_trim)
	{
		if (!ft_strchr(set, s1[back_trim]))
			found_differance = 1;
		else
			back_trim--;
	}
	return (ft_substr(s1, front_trim, (back_trim + 1) - front_trim));
}
