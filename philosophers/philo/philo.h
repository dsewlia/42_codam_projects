/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:47:06 by dsewlia           #+#    #+#             */
/*   Updated: 2025/05/01 13:12:02 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PHILO 1000

//to remove
typedef struct s_time
{
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		times_to_eat;
	int		last_meal;
	int		born_time;
}	t_time;

typedef struct s_mutex
{
	pthread_mutex_t	*l;
	pthread_mutex_t	*r;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
}	t_mutex;

typedef struct s_philo
{
	int			id;
	t_time		times; //to remove
	t_mutex		mutexes;
	int			must_eat;
	pthread_t	thread_id;
	int			times_eaten;
	int			count_philo;
	size_t		last_meal;
	size_t		born_time;
	size_t		die_time;
	int			sleep_time;
	int			eat_time;
	int			times_to_eat;
}	t_philo;

typedef struct s_data
{
	int				count_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				times_to_eat;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}	t_data;

size_t	get_current_time(void);
void	ft_usleep(size_t ms);
void	error_msg(char *msg, t_data *data, int count, bool flag);
void	init_mutexes(t_data *data);
void	init_philo_struct(t_data *data);
bool	end_of_dinner(t_data *data);
void	*control_func(void *p);
void	philo_eats(t_philo *philo);
void	*sim(void *p);
void	lets_dine(t_data *data);
void	display_msg(t_philo *philo, char *s);
int		main(int argc, char **argv);
