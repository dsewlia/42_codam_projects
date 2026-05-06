/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:30 by dsewlia           #+#    #+#             */
/*   Updated: 2024/11/06 10:46:59 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_print_str(char *s);
int	ft_print_nbr(int n, int count, size_t i);
int	ft_print_unsigned_nbr(unsigned int n);
int	ft_print_hex_2(unsigned int n, const char c, char *hex_big,
		char *hex_small);
int	ft_print_hex(unsigned long int n, const char c);
int	ft_print_char(int i);
int	ft_print_pointer_2(unsigned long n, char *hex_small);
int	ft_print_pointer(uintptr_t a);
int	check_arg(va_list arg, const char c);
int	ft_printf(const char *format, ...);

#endif