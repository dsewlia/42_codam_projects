/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_unset_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:40:02 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/07 15:43:42 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_sorted_env_2(char **dup_env, int i)
{
	char	*temp;
	int		j;

	j = 0;
	while (j < i)
	{
		while (j < i - 1)
		{
			if (ft_strncmp(dup_env[j], dup_env[j + 1], \
				ft_strlen(dup_env[j])) > 0)
			{
				temp = dup_env[j];
				dup_env[j] = dup_env[j + 1];
				dup_env[j + 1] = temp;
			}
			j++;
		}
		j = 0;
		i--;
	}
	return (dup_env);
}

char	**get_sorted_env(char **env)
{
	char	**dup_env;
	int		i;

	i = 0;
	while (env[i] != NULL)
		i++;
	dup_env = (char **)ft_calloc(i + 1, sizeof(char *));
	if (dup_env == NULL)
		return (NULL);
	i = 0;
	while (env[i] != NULL)
	{
		dup_env[i] = ft_strdup(env[i]);
		if (dup_env[i] == NULL)
			return (ft_free_double(dup_env, NULL, NULL, NULL), NULL);
		i++;
	}
	dup_env[i] = NULL;
	return (get_sorted_env_2(dup_env, i));
}
