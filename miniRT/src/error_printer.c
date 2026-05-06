/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:00:23 by driemers          #+#    #+#             */
/*   Updated: 2025/04/22 16:27:39 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minirt.h"
#include <unistd.h>

int	print_warn(char *str)
{
	write(STDERR_FILENO, "Warning\n", 9);
	write(STDERR_FILENO, str, ft_strlen(str));
	return (0);
}

int	print_err(char *str)
{
	write(STDERR_FILENO, "Error\n", 7);
	write(STDERR_FILENO, str, ft_strlen(str));
	return (0);
}

void	*print_err_null(char *str)
{
	print_err(str);
	return (NULL);
}

void	*print_err_fail_null(char *str, int *fail)
{
	print_err_fail(str, fail);
	return (NULL);
}

int	print_err_fail(char *str, int *fail)
{
	*fail = 1;
	print_err(str);
	return (0);
}
