/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:33:04 by dsewlia           #+#    #+#             */
/*   Updated: 2024/11/04 21:33:17 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_the_line_2(char **fd_log, char *new_line, int fd, size_t i)
{
	size_t	j;
	char	*new_log;

	j = 0;
	while (fd_log[fd][i + j] != '\0')
		j++;
	new_log = (char *)malloc(sizeof(char) * (j + 1));
	if (new_log == NULL)
	{
		free (new_line);
		free (fd_log[fd]);
		fd_log[fd] = NULL;
		return (NULL);
	}
	j = 0;
	while (fd_log[fd][i + j] != '\0')
	{
		new_log[j] = fd_log[fd][i + j];
		j++;
	}
	new_log[j] = '\0';
	free (fd_log[fd]);
	fd_log[fd] = new_log;
	return (new_line);
}

char	*get_the_line(char **fd_log, int fd, size_t i, size_t j)
{
	char	*new_line;

	new_line = (char *)malloc(sizeof(char) * i + 1);
	if (new_line == NULL)
	{
		free (fd_log[fd]);
		fd_log[fd] = NULL;
		return (NULL);
	}
	while (j < i)
	{
		new_line[j] = fd_log[fd][j];
		j++;
	}
	new_line[j] = '\0';
	if (fd_log[fd][j] == '\0')
	{
		free (fd_log[fd]);
		fd_log[fd] = NULL;
		return (new_line);
	}
	return (get_the_line_2(fd_log, new_line, fd, j));
}

char	*reset_fd_2(char *new_fd)
{
	free (new_fd);
	new_fd = NULL;
	return (NULL);
}

char	*reset_fd(char **fd_log, int fd, size_t i, size_t j)
{
	char		*new_fd;
	long int	r;

	new_fd = (char *)malloc(sizeof(char) * (i + BUFFER_SIZE + 1));
	if (new_fd == NULL)
	{
		free (fd_log[fd]);
		fd_log[fd] = NULL;
		return (NULL);
	}
	while (j < i)
	{
		new_fd[j] = fd_log[fd][j];
		j++;
	}
	new_fd[j] = '\0';
	free (fd_log[fd]);
	fd_log[fd] = NULL;
	r = read (fd, &new_fd[j], BUFFER_SIZE);
	if (r < 0)
		return (reset_fd_2(new_fd));
	new_fd[j + r] = '\0';
	return (new_fd);
}

char	*get_next_line_2(char **fd_log, int fd, size_t i, size_t j)
{
	while (j == 0)
	{
		while (fd_log[fd][i] != '\n' && fd_log[fd][i] != '\0')
			i++;
		if (fd_log[fd][i] == '\n')
			return (get_the_line(fd_log, fd, i + 1, 0));
		if (fd_log[fd][i] == '\0')
		{
			fd_log[fd] = reset_fd(fd_log, fd, i, 0);
			if (fd_log[fd] == NULL)
				return (NULL);
			if (fd_log[fd][i] == '\0')
				return (get_the_line(fd_log, fd, i, 0));
		}
		else
			j = 1;
	}
	free (fd_log[fd]);
	fd_log[fd] = NULL;
	return (NULL);
}
