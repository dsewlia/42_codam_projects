/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:56:07 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/06 11:45:08 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	fn_receive_message(int sig)
{
	static int	count = 0;
	static int	c = 0;
	static int	b = 1;
	char		a;

	if (sig == SIGUSR1)
		c = c + b;
	count++;
	b = b * 2;
	if (count == 8)
	{
		a = c;
		write (1, &a, 1);
		c = 0;
		b = 1;
		count = 0;
	}
}

void	fn_print_pid(unsigned int n)
{
	char	a[15];
	int		i;

	i = 0;
	if (n == 0)
	{
		write (1, "0", 1);
	}
	while (n > 0)
	{
		a[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (i-- > 0)
		write (1, &a[i], 1);
}

int	main(void)
{
	int		p_id;

	p_id = getpid();
	write(1, "Server PID: ", 12);
	fn_print_pid(p_id);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, fn_receive_message);
		signal(SIGUSR2, fn_receive_message);
		pause ();
	}
	return (0);
}
