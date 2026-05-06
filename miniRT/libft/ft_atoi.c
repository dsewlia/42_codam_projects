/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:35:49 by driemers          #+#    #+#             */
/*   Updated: 2024/10/24 16:51:25 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	pow_ten(int times)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < times)
	{
		result *= 10;
		i++;
	}
	return (result);
}

static int	num_lenght(char *str)
{
	int	count;

	count = 0;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		count++;
	}
	count--;
	return (count);
}

static char	*check_white_spaces(char *str)
{
	while ((*str >= '\t' && *str <= '\r')
		|| (*str == ' ' || *str == '	'))
	{
		str++;
	}
	return (str);
}

int	ft_atoi(const char *nptr)
{
	int		count;
	int		total;
	int		invert;
	char	*str;

	str = (char *) nptr;
	invert = 0;
	total = 0;
	count = 0;
	str = check_white_spaces(str);
	if (*str == '-')
		invert++;
	if (*str == '+' || *str == '-')
		str++;
	count = num_lenght(str);
	while (*str >= '0' && *str <= '9')
	{
		total += ((*str - 48) * pow_ten(count));
		str++;
		count--;
	}
	if (invert == 1)
		return (total *= -1);
	return (total);
}
