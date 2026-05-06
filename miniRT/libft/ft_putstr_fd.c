/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:38:53 by driemers          #+#    #+#             */
/*   Updated: 2024/10/17 17:46:56 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	index = 0;
	while (s[index] != 0)
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}
