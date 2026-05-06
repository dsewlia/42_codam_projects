/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:16:54 by dsewlia           #+#    #+#             */
/*   Updated: 2024/11/06 16:25:12 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int i)
{
	char	a;

	a = i;
	write (1, &a, 1);
	return (1);
}

int	ft_print_pointer_2(unsigned long n, char *hex_small)
{
	int		i;
	char	nbr[16];
	int		count;

	count = 0;
	i = 0;
	while (n > 0)
	{
		nbr[i] = hex_small[n % 16];
		n = n / 16;
		i++;
	}
	while (i-- > 0 && count++ >= 0)
	{
		write (1, &nbr[i], 1);
	}
	return (count);
}

int	ft_print_pointer(uintptr_t a)
{
	char				hex_small[17];
	unsigned long int	n;
	int					i;

	i = 0;
	n = a;
	if (a == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	while (i < 10)
	{
		hex_small[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		hex_small[i] = i + 87;
		i++;
	}
	write (1, "0x", 2);
	return (2 + ft_print_pointer_2(n, hex_small));
}

int	check_arg(va_list arg, const char c)
{
	int		count;

	count = 0;
	if (c == 'c')
		return (ft_print_char(va_arg(arg, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (c == '%')
		return (ft_print_char(37));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(arg, uintptr_t)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(arg, int), 0, 0));
	else if (c == 'u')
		return (ft_print_unsigned_nbr(va_arg(arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), c));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	int			count;

	va_start(arg, format);
	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			count = count + ft_print_char(format[i++]);
		if (format[i] == '%')
		{
			count = count + check_arg(arg, format[++i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
