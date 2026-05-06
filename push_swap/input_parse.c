/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:38:16 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/02 15:29:16 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fn_input_parse_2(char **x, int status, int i)
{
	if (status == 0)
	{
		x[i - 1] = NULL;
		return (x);
	}
	while (i-- > 0)
	{
		if (x[i] != NULL)
		{
			free (x[i]);
			x[i] = NULL;
		}
	}
	free (x);
	x = NULL;
	return (x);
}

char	**fn_input_parse(char **x, char **argv, int n)
{
	int		i;
	int		j;
	int		status;

	i = 1;
	status = 0;
	while (i < n && status == 0)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				status = 1;
			j++;
		}
		if (status == 0)
			x[i - 1] = fn_argv_copy(argv[i]);
		if (status == 0 && x[i - 1] == NULL)
			status = 1;
		i++;
	}
	return (fn_input_parse_2(x, status, i));
}
