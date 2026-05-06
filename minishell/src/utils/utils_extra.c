/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:12:51 by osivkov           #+#    #+#             */
/*   Updated: 2025/04/07 15:49:49 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(t_cmd *head)
{
	if (head->infile == head->outfile && head->infile > 2)
	{
		close(head->infile);
		return ;
	}
	if (head->infile > 2)
		close(head->infile);
	if (head->outfile > 2)
		close(head->outfile);
}

int	ft_isspace(int c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

int	is_operator_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}
