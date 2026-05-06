/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:40:05 by driemers          #+#    #+#             */
/*   Updated: 2024/10/18 16:01:38 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	n_base_ten_size(int n)
{
	int		index;

	index = 1;
	while (n < -9)
	{
		n /= 10;
		index++;
	}
	return (index);
}

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	sign_ft(int n)
{
	if (n < 0)
		return (1);
	return (-1);
}

static char	*populate_string(int n, int size, int sign, char *string)
{
	int		index;

	index = size + sign;
	if (sign)
		string[0] = '-';
	while (index > sign)
	{
		index--;
		if (n < -9)
		{
			string[index] = (char)(((n % 10) * -1) + '0');
			n /= 10;
		}
		else
			string[index] = ((char)n * -1) + '0';
	}
	string[size + sign] = 0;
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		size;
	int		sign;

	sign = is_negative(n);
	n *= sign_ft(n);
	size = n_base_ten_size(n);
	string = malloc(sizeof(char) * size + 1 + sign);
	if (string == NULL)
		return (NULL);
	return (populate_string(n, size, sign, string));
}
