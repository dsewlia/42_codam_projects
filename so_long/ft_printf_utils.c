/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:52:57 by dsewlia           #+#    #+#             */
/*   Updated: 2024/11/06 11:27:46 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_print_nbr(int n, int count, size_t i)
{
	char		a[15];
	long int	n1;

	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		write (1, "-", 1);
		count++;
	}
	else if (n1 == 0)
	{
		write (1, "0", 1);
		count++;
	}
	while (n1 > 0)
	{
		a[i++] = (n1 % 10) + '0';
		n1 = n1 / 10;
	}
	while (i-- > 0 && count++ >= 0)
		write (1, &a[i], 1);
	return (count);
}

int	ft_print_unsigned_nbr(unsigned int n)
{
	int		count;
	char	a[15];
	int		i;

	i = 0;
	count = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		a[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (i-- > 0 && count++ >= 0)
		write (1, &a[i], 1);
	return (count);
}

int	ft_print_hex_2(unsigned int n, const char c, char *hex_big, char *hex_small)
{
	int		i;
	char	nbr[16];
	int		count;

	i = 0;
	count = 0;
	while (n > 0)
	{
		if (c == 'x')
		{
			nbr[i] = hex_small[n % 16];
			n = n / 16;
			i++;
		}
		else
		{
			nbr[i] = hex_big[n % 16];
			n = n / 16;
			i++;
		}
	}
	while (i-- > 0 && count++ >= 0)
		write (1, &nbr[i], 1);
	return (count);
}

int	ft_print_hex(unsigned long int n, const char c)
{
	char	hex_small[17];
	char	hex_big[17];
	int		i;

	i = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	while (i < 10)
	{
		hex_big[i] = i + '0';
		hex_small[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		hex_big[i] = i + 55;
		hex_small[i] = i + 87;
		i++;
	}
	hex_small[16] = '\0';
	hex_big[16] = '\0';
	return (ft_print_hex_2(n, c, hex_big, hex_small));
}
