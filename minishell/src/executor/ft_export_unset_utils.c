/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_unset_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:47:54 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/07 15:39:22 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//adds new env variable to the end of env.
int	ft_export_add_new(t_minishell *mini, char *str, int i)
{
	char	**new_env;

	new_env = (char **)ft_calloc(sizeof(char *), (i + 2));
	if (new_env == NULL)
		return (1);
	i = -1;
	while (mini->env[++i] != NULL)
		new_env[i] = mini->env[i];
	new_env[i] = ft_strdup(str);
	new_env[i + 1] = NULL;
	free (mini->env);
	mini->env = new_env;
	return (0);
}

int	ft_export_concat_2(t_minishell *mini, int i, char *key, char *value)
{
	char	*temp;
	char	**new_env;

	temp = ft_strjoin_all(key, value, NULL, NULL);
	ft_free_single(key, value, NULL, NULL);
	if (temp == NULL)
		return (1);
	new_env = (char **)ft_calloc(sizeof(char *), (i + 2));
	if (new_env == NULL)
		return (free (temp), 1);
	i = -1;
	while (mini->env[++i] != NULL)
		new_env[i] = mini->env[i];
	new_env[i] = temp;
	new_env[i + 1] = NULL;
	free (mini->env);
	mini->env = new_env;
	return (0);
}

int	ft_export_concat_3(t_minishell *mini, int i, char *key, char *value)
{
	char	*temp;

	temp = ft_strdup(mini->env[i]);
	if (temp == NULL)
		return (ft_free_single(value, key, NULL, NULL), 1);
	free (mini->env[i]);
	mini->env[i] = ft_strjoin_all(temp, value, NULL, NULL);
	return (ft_free_single(value, key, temp, NULL), 0);
}

int	ft_export_concat(t_minishell *mini, char *str, int i)
{
	char	*value;
	char	*key;

	value = ft_substr(str, 0, i);
	if (value == NULL)
		return (1);
	key = ft_strjoin_all(value, "=", NULL, NULL);
	ft_free_single(value, NULL, NULL, NULL);
	if (key == NULL)
		return (1);
	value = ft_substr(str, i + 2, ft_strlen(str) - i + 1);
	if (value == NULL)
		return (free (key), 1);
	i = 0;
	while (mini->env[i] != NULL && \
		ft_strncmp(key, mini->env[i], ft_strlen(key)) != 0)
		i++;
	if (mini->env[i] == NULL)
		return (ft_export_concat_2(mini, i, key, value));
	return (ft_export_concat_3(mini, i, key, value));
}
