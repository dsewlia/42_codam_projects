/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:46:47 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/01 13:02:36 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define MAX_PHILO 1000

//i = 0, j = 0, th = 1when parsed. returns -1 if it is not a +ve whole number
int	custom_atoi(char *s, int i, int j, int th)
{
	int		x;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '+')
		i++;
	x = i;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	j = i;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != '\0')
		return (-1);
	i = -1;
	while (++i < j - x - 1)
		th *= 10;
	x--;
	i = 0;
	while (++x < j)
	{
		i = i + ((s[x] - '0') * th);
		th = th / 10;
	}
	return (i);
}

void	check_arg(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		error_msg("Number of argument mismatch", data, 0, false);
	data->count_philo = custom_atoi(argv[1], 0, 0, 1);
	data->die_time = custom_atoi(argv[2], 0, 0, 1);
	data->eat_time = custom_atoi(argv[3], 0, 0, 1);
	data->sleep_time = custom_atoi(argv[4], 0, 0, 1);
	if (data->count_philo <= 0 || data->die_time <= 0 || data->eat_time <= 0 || \
		data->sleep_time <= 0)
		error_msg("Argument doesn't follow input constraints", data, 0, false);
	data->times_to_eat = -1;
	if (argv[5] != NULL)
	{
		data->times_to_eat = custom_atoi(argv[5], 0, 0, 1);
		if (data->times_to_eat <= 0)
			error_msg("Argument doesn't follow input constraints", data, 0, \
				false);
	}
}

void	display_msg(t_philo *philo, char *s)
{
	size_t	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = get_current_time() - philo->born_time;
	printf("%ld %d %s\n", time, philo->id, s);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}

int	main(int argc, char **argv)
{
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];
	t_data			data;
	int				i;

	data.forks = forks;
	data.philos = philos;
	check_arg(argc, argv, &data);
	init_mutexes(&data);
	init_philo_struct(&data);
	lets_dine(&data);
	i = -1;
	while (++i < data.count_philo)
		pthread_mutex_destroy(&data.forks[i]);
	pthread_mutex_destroy(&data.write_lock);
	pthread_mutex_destroy(&data.meal_lock);
	return (0);
}
