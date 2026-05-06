/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:32:37 by dsewlia           #+#    #+#             */
/*   Updated: 2024/11/04 21:32:46 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*fd_log[1024];
	long int	a;

	if (fd < 0 || fd > 1023 || fd == 1)
		return (NULL);
	if (fd_log[fd] == NULL)
	{
		fd_log[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
		if (fd_log[fd] == NULL)
			return (NULL);
		a = read (fd, &fd_log[fd][0], BUFFER_SIZE);
		if (a <= 0)
		{
			free (fd_log[fd]);
			fd_log[fd] = NULL;
			return (NULL);
		}
		fd_log[fd][a] = '\0';
	}
	return (get_next_line_2(fd_log, fd, 0, 0));
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	int		r;

// 	fd = open(argv[1], O_RDONLY);
// 	if (argc == 1)
// 		return (0);
// 	printf("gnl? press 1\n");
// 	scanf("%d", &r);
// 	while (r == 1)
// 	{
// 		printf("%s", get_next_line(fd));
// 		printf("gnl? press 1\n");
// 		scanf("%d", &r);
// 	}
// 	return (0);
// }
