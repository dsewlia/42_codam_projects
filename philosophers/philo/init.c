/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:00:40 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/01 13:03:54 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t ms)
{
	size_t	i;

	i = get_current_time();
	while (get_current_time() - i < ms)
		usleep(500);
}

void	error_msg(char *msg, t_data *data, int count, bool flag)
{
	int		i;

	i = -1;
	while (++i < count)
		pthread_mutex_destroy(&data->forks[i]);
	if (flag)
	{
		pthread_mutex_destroy(&data->write_lock);
		pthread_mutex_destroy(&data->meal_lock);
	}
	printf ("%s\n", msg);
	exit(1);
}

void	init_mutexes(t_data *data)
{
	int		i;

	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		error_msg("Unable to initialize mutexes", data, 0, false);
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		error_msg("Unable to initialize mutexes", data, 0, false);
	}
	i = -1;
	while (++i < data->count_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			error_msg("Unable to initialize mutexes", data, i, true);
	}
}

void	init_philo_struct(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->count_philo)
	{
		data->philos[i].count_philo = data->count_philo;
		data->philos[i].id = i + 1;
		data->philos[i].die_time = data->die_time;
		data->philos[i].eat_time = data->eat_time;
		data->philos[i].sleep_time = data->sleep_time;
		data->philos[i].times_to_eat = data->times_to_eat;
		data->philos[i].last_meal = get_current_time();
		data->philos[i].born_time = get_current_time();
		data->philos[i].mutexes.write_lock = &data->write_lock;
		data->philos[i].mutexes.meal_lock = &data->meal_lock;
		data->philos[i].mutexes.l = &data->forks[i];
		if (i == 0)
			data->philos[i].mutexes.r = &data->forks[data->count_philo - 1];
		else
			data->philos[i].mutexes.r = &data->forks[i - 1];
	}
}
