/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:01:39 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/01 13:03:36 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	end_of_dinner(t_data *data)
{
	int		i;
	int		eaten;

	if (data->times_to_eat == -1)
		return (false);
	eaten = 0;
	i = -1;
	while (++i < data->count_philo)
	{
		pthread_mutex_lock(data->philos[i].mutexes.meal_lock);
		if (data->philos[i].times_eaten >= data->philos[i].times_to_eat)
			eaten++;
		pthread_mutex_unlock(data->philos[i].mutexes.meal_lock);
	}
	if (eaten == data->count_philo)
	{
		pthread_mutex_lock(data->philos[0].mutexes.write_lock);
		return (true);
	}
	return (false);
}

void	*control_func(void *p)
{
	t_data	*data;
	int		i;

	data = (t_data *)p;
	while (1)
	{
		i = -1;
		while (++i < data->count_philo)
		{
			pthread_mutex_lock(data->philos[i].mutexes.meal_lock);
			if (get_current_time() - data->philos[i].last_meal > \
				data->philos[i].die_time)
			{
				pthread_mutex_unlock(data->philos[i].mutexes.meal_lock);
				display_msg(&data->philos[i], "died");
				pthread_mutex_lock(data->philos[i].mutexes.write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(data->philos[i].mutexes.meal_lock);
		}
		if (end_of_dinner(data))
			return (NULL);
	}
	return (NULL);
}

void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.l);
	display_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->mutexes.r);
	display_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	display_msg(philo, "is eating");
	philo->last_meal = get_current_time();
	philo->times_eaten++;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->eat_time);
	pthread_mutex_unlock(philo->mutexes.l);
	pthread_mutex_unlock(philo->mutexes.r);
	display_msg(philo, "is sleeping");
	ft_usleep(philo->sleep_time);
	display_msg(philo, "is thinking");
}

void	*sim(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		ft_usleep(philo->eat_time / 10);
	while (true)
		philo_eats(philo);
	return (NULL);
}

void	lets_dine(t_data *data)
{
	pthread_t	main_id;
	int			i;

	if (pthread_create(&main_id, NULL, &control_func, data) != 0)
		error_msg("Thread creation failed", data, data->count_philo, true);
	i = -1;
	while (++i < data->count_philo)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, \
			&sim, &data->philos[i]) != 0)
			error_msg("Thread creation failed", data, data->count_philo, true);
	}
	if (pthread_join(main_id, NULL) != 0)
		error_msg("Thread joining failed", data, data->count_philo, true);
	i = -1;
	while (++i < data->count_philo)
	{
		if (pthread_detach(data->philos[i].thread_id) != 0)
			error_msg("Thread detact failed", data, data->count_philo, true);
	}
}
