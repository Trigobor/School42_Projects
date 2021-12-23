/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:33:27 by eosfryd           #+#    #+#             */
/*   Updated: 2021/10/24 17:14:20 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *memory)
{
	t_phil	*philo;

	philo = (t_phil *)memory;
	while (philo->main->is_all_alive == 1 && philo->lunch != 0)
	{
		pthread_mutex_lock(&philo->left->fork);
		print_status(KEEPS, philo->main, philo->count);
		pthread_mutex_lock(&philo->right->fork);
		gettimeofday(&philo->lastf, NULL);
		print_status(FEAST, philo->main, philo->count);
		if (philo->lunch != -1)
			philo->lunch--;
		ms_sleep(philo->main->input.time_to_eat);
		pthread_mutex_unlock(&philo->right->fork);
		pthread_mutex_unlock(&philo->left->fork);
		print_status(SLEEP, philo->main, philo->count);
		ms_sleep(philo->main->input.time_to_nap);
		print_status(THINK, philo->main, philo->count);
	}
	return (NULL);
}

void	take_your_forks(t_main *g_struct, int i, int last)
{
	t_fork	*forks;
	t_phil	*phil;

	phil = &g_struct->phils[i];
	phil->count = i;
	phil->main = g_struct;
	forks = g_struct->forks;
	if (i % 2 == 0)
	{
		phil->left = &forks[i];
		if (i != last)
			phil->right = &forks[i + 1];
		else
			phil->right = &forks[0];
	}
	else
	{
		if (i != last)
			phil->left = &forks[i + 1];
		else
			phil->left = &forks[0];
		phil->right = &forks[i];
	}
	phil->lunch = g_struct->input.num_of_eats;
}

void	start_philosophizing(t_main *g_struct, int i)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	g_struct->start = ((useconds_t)(time.tv_sec * 1000000) + time.tv_usec);
	while (i < g_struct->input.num_of_phil)
	{
		g_struct->phils[i].lastf = time;
		pthread_create(&g_struct->phils[i].thread, \
		NULL, philosopher, (void *)&g_struct->phils[i]);
		pthread_detach(g_struct->phils[i++].thread);
	}
}

void	start_overseeing(t_main *g_struct, int n, int die)
{
	int				i;
	struct timeval	now;

	while (g_struct->is_all_alive && feedcheck(g_struct))
	{
		i = 0;
		while (i < n && g_struct->phils[i].lunch != 0)
		{
			gettimeofday(&now, NULL);
			if (lifecheck(now, g_struct->phils[i].lastf, die))
			{
				g_struct->is_all_alive = 0;
				shut_down(i, g_struct);
				break ;
			}
			i++;
		}
		ms_sleep(10);
	}
}

int	main(int ac, char **av)
{
	t_main	g;
	int		i;

	printf("%s", ACTUAL);
	if (read_args(ac, av, &g.input) == 0)
		return (0);
	i = 0;
	g.is_all_alive = 1;
	g.is_all_empty = 1;
	g.forks = (t_fork *)malloc(sizeof(t_fork) * g.input.num_of_phil);
	g.phils = (t_phil *)malloc(sizeof(t_phil) * g.input.num_of_phil);
	pthread_mutex_init(&g.report, NULL);
	while (i < g.input.num_of_phil)
	{
		pthread_mutex_init(&g.forks[i].fork, NULL);
		pthread_mutex_init(&g.phils[i].mutex, NULL);
		g.forks[i].count = i;
		take_your_forks(&g, i++, g.input.num_of_phil - 1);
	}
	start_philosophizing(&g, 0);
	start_overseeing(&g, g.input.num_of_phil, g.input.time_to_die * 1000);
	philo_clean(&g);
	return (0);
}
