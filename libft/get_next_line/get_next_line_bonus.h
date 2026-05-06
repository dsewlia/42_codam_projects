/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:33:28 by dsewlia           #+#    #+#             */
/*   Updated: 2024/11/04 21:33:44 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*reset_fd_2(char *new_fd);
char	*reset_fd(char **fd_log, int fd, size_t i, size_t j);
char	*get_the_line_2(char **fd_log, char *new_line, int fd, size_t i);
char	*get_the_line(char **fd_log, int fd, size_t i, size_t j);
char	*get_next_line_2(char **fd_log, int fd, size_t i, size_t j);
char	*get_next_line(int fd);

#endif