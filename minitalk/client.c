/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:55:59 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/06 11:43:14 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	fn_custom_atoi_pid(const char *a)
{
	int		i;
	int		sign;
	int		th;
	int		num;

	i = 0;
	while (a[i] != '\0')
		i++;
	sign = 0;
	if (a[0] == '-')
		return (-1);
	else if (a[0] == '+')
		sign++;
	th = 1;
	num = 0;
	while (i-- > (0 + sign))
	{
		if (a[i] < '0' || a[i] > '9')
			return (-1);
		num = num + ((a[i] - '0') * th);
		th = th * 10;
	}
	return (num);
}

void	fn_send_message(int pid, const char *s)
{
	int		i;
	int		a;
	int		count;

	i = 0;
	while (s[i] != '\0')
	{
		a = s[i];
		count = 0;
		while (count++ < 8)
		{
			if (a % 2 == 1)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			a = a / 2;
			usleep(300);
		}
		usleep(300);
		i++;
	}
}

int	main(int argc, char const **argv)
{
	int		pid;

	if (argc != 3)
	{
		write (2, "Please give 2 arguments as follows:\n", 36);
		write (2, "1. PID\n2. Message\nThank you\n", 28);
		return (1);
	}
	pid = fn_custom_atoi_pid(argv[1]);
	if (pid == -1)
	{
		write (2, "PID error\n", 10);
		return (1);
	}
	fn_send_message(pid, argv[2]);
	return (0);
}
