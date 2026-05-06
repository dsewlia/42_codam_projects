/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:48:08 by dsewlia           #+#    #+#             */
/*   Updated: 2025/04/07 15:45:24 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*will write the cmd path into path and free temp path and return 0
if path is not found, it will print error message and return errno*/
int	get_final_path(t_minishell *mini, char **all_path, char *path, \
	char *to_find)
{
	char	*full_path;
	int		i;
	int		j;

	i = -1;
	while (all_path[++i] != NULL)
	{
		full_path = ft_strjoin_all(all_path[i], "/", to_find, NULL);
		if (full_path == NULL)
			return (ft_free_double(all_path, NULL, NULL, NULL), \
				free (full_path), ft_malloc_error(mini), ENOMEM);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			j = -1;
			while (full_path[++j] != '\0')
				path[j] = full_path[j];
			path[j] = '\0';
			ft_free_double(all_path, NULL, NULL, NULL);
			return (free (full_path), 0);
		}
		ft_free_single(full_path, NULL, NULL, NULL);
	}
	ft_free_double(all_path, NULL, NULL, NULL);
	return (ft_error_msg(to_find, NULL, "command not found"), 127);
}

/*will return 0 if cmd path is found and wil write it into path
if cmd path is not found, it will print error message and return errno*/
int	get_cmd_path(t_minishell *mini, char *to_find, char *path)
{
	char	*temp;
	char	**all_path;

	temp = ft_get_env_var(mini, "PATH");
	if (temp == NULL)
		return (ft_malloc_error(mini), ENOMEM);
	else if (ft_strncmp(temp, "", 1) == 0)
	{
		printf("minishell: %s: No such file or directory\n", to_find);
		return (free (temp), 127);
	}
	all_path = ft_split(temp, ':');
	ft_free_single(temp, NULL, NULL, NULL);
	if (all_path == NULL)
		return (ft_malloc_error(mini), ENOMEM);
	return (get_final_path(mini, all_path, path, to_find));
}

int	ft_sys_builtin_2(t_minishell *mini, t_cmd *head, char *path, \
	int exit_status)
{
	if (is_directory(path))
		return (ft_error_msg(head->args[0], NULL, "Is a directory"), 126);
	if (execve(path, head->args, mini->env) == -1)
	{
		mini->last_exit = errno;
		return (ft_error_msg(head->args[0], NULL, strerror(errno)), errno);
	}
	return (exit_status);
}

/*will initiate sys_cmd and will return exit_status of the cmd*/
int	ft_sys_builtin(t_minishell *mini, t_cmd *head, int i, int exit_status)
{
	char	path[PATH_MAX];

	if (head->args != NULL && ft_strncmp(head->args[0], "", 1) == 0)
		return (ft_error_msg("\'\'", NULL, "command not found"), 127);
	if (access(head->args[0], F_OK | X_OK) == 0)
	{
		i = -1;
		while (head->args[0][++i] != '\0')
			path[i] = head->args[0][i];
		path[i] = '\0';
	}
	else if (head->args[0][0] == '.' || head->args[0][0] == '/')
		return (ft_error_msg(head->args[0], NULL, "No such file or directory"), \
			127);
	else
	{
		exit_status = get_cmd_path(mini, head->args[0], path);
		if (exit_status != 0)
			return (exit_status);
	}
	return (ft_sys_builtin_2(mini, head, path, exit_status));
}

/*if it is built in and is the only cmd
	->it returns the exit_status of the command
else it exits with the exit status
*/
int	begin_builtin(t_minishell *mini, t_cmd *head)
{
	int		exit_status;

	exit_status = 0;
	if (ft_strncmp(head->args[0], "cd", 3) == 0)
		exit_status = ft_cd(mini, head);
	else if (ft_strncmp(head->args[0], "echo", 5) == 0)
		exit_status = ft_echo(mini, head, 0, 0);
	else if (ft_strncmp(head->args[0], "env", 4) == 0)
		exit_status = ft_env(mini, head);
	else if (ft_strncmp(head->args[0], "export", 7) == 0)
		exit_status = ft_export(mini, head);
	else if (ft_strncmp(head->args[0], "pwd", 4) == 0)
		exit_status = ft_pwd(mini, head);
	else if (ft_strncmp(head->args[0], "unset", 6) == 0)
		exit_status = ft_unset(mini, head);
	else if (ft_strncmp(head->args[0], "exit", 5) == 0)
		exit_status = ft_exit(mini, head);
	else
		exit_status = ft_sys_builtin(mini, head, 0, 0);
	if (mini->cmd->next == NULL && check_builtin(head) == 0)
		return (exit_status);
	free_minishell(mini);
	exit(exit_status);
	return (exit_status);
}
