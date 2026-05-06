/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:48:47 by driemers          #+#    #+#             */
/*   Updated: 2024/10/23 14:29:23 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	write_num(int n, int fd)
{
	if (n < -9)
	{
		write_num(n / 10, fd);
		ft_putchar_fd((char)(((n % 10) * -1) + '0'), fd);
	}
	else
		ft_putchar_fd(((char)n * -1) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;

	sign = is_negative(n);
	n *= sign_ft(n);
	if (sign)
		ft_putchar_fd('-', fd);
	write_num(n, fd);
}

// int	main(void)
// {
// 	ft_putnbr_fd(2147483647, 1);
// 	ft_putnbr_fd(-2147483648, 1);
// 	//ft_putnbr_fd(2655, 1);
// }
