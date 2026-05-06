/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:46:33 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:52:21 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		a[15];
	int			i;
	long int	n1;

	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		write (fd, "-", 1);
	}
	else if (n1 == 0)
		write (fd, "0", 1);
	i = 0;
	while (n1 > 0)
	{
		a[i] = (n1 % 10) + '0';
		n1 = n1 / 10;
		i++;
	}
	while (i > 0)
	{
		write (fd, &a[i - 1], 1);
		i--;
	}
}

// int	main(void)
// {
// 	int		n = 2147483647;

// 	ft_putnbr_fd(n, 1);
// 	return (0);
// }
