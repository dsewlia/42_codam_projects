/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:10:38 by driemers          #+#    #+#             */
/*   Updated: 2024/10/25 15:04:51 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static void	free_double_arr(char **s_arr, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		free(s_arr[index]);
		index++;
	}
}

static char	**look_for_null(char **s_arr, size_t size)
{
	size_t	index;
	int		found_null;

	index = 0;
	found_null = 0;
	while (index < size && !found_null)
	{
		if (s_arr[index] == NULL)
			found_null++;
		index++;
	}
	if (found_null)
	{
		free_double_arr(s_arr, size);
		free(s_arr);
		return (NULL);
	}
	return (s_arr);
}

static size_t	array_size(char const *s, char c)
{
	size_t	index;
	size_t	array_index;
	char	last_char;

	index = 0;
	array_index = 0;
	last_char = c;
	while (s[index] != 0)
	{
		if (s[index] != c && last_char == c)
		{
			array_index++;
		}
		last_char = s[index];
		index++;
	}
	return (array_index);
}

static char	*add_string(size_t string_start, char const *s, char c)
{
	char	*string;
	size_t	index;

	index = 0;
	while (s[index + string_start] != 0 && s[index + string_start] != c)
		index++;
	string = ft_substr(s, string_start, index);
	if (string == NULL)
		return (NULL);
	return (string);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**string_array;
	size_t	array_index;
	char	last_char;

	array_index = 0;
	index = 0;
	last_char = c;
	string_array = malloc(sizeof(char *) * (array_size(s, c) + 1));
	if (string_array == NULL || ft_strlen(s) == 1)
		return (NULL);
	while (s[index] != 0)
	{
		if (s[index] != c && last_char == c)
		{
			string_array[array_index] = add_string(index, s, c);
			array_index++;
		}
		last_char = s[index];
		index++;
	}
	string_array[array_index] = NULL;
	return (look_for_null(string_array, array_index));
}

// #include <stdio.h>

// int main(void)
// {
// 	char	delimiter;
// 	char	*str;
// 	char	**str_arr;

// 	delimiter = 'n';
// 	str = "aaa";
// 	str_arr = ft_split(str, delimiter);
// 	while (*str_arr != NULL)
// 	{
// 		printf("boop:%s\n", *str_arr);
// 		str_arr++;
// 	}
// }
