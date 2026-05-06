/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:42:10 by dsewlia           #+#    #+#             */
/*   Updated: 2024/10/14 12:52:26 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

// int	main(void)
// {
// 	char	c[] = "hello";

// 	ft_putstr_fd(c, 1);
// 	return (0);
// }
