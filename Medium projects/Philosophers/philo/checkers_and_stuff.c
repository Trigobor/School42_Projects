/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_and_stuff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:18:20 by eosfryd           #+#    #+#             */
/*   Updated: 2021/10/24 17:02:56 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_clean(t_main *g_struct)
{
	int	i;

	i = 0;
	if (g_struct)
	{
		while (i < g_struct->input.num_of_phil)
		{
			pthread_mutex_destroy(&g_struct->forks[i].fork);
			pthread_mutex_destroy(&g_struct->phils[i].mutex);
			i++;
		}
		pthread_mutex_destroy(&g_struct->report);
		if (g_struct->forks)
		{
			free(g_struct->forks);
			g_struct->forks = NULL;
		}
		if (g_struct->phils)
		{
			free(g_struct->phils);
			g_struct->phils = NULL;
		}
	}
	printf("%s", COLOR);
}

int	lifecheck(struct timeval time, struct timeval lastf, int die)
{
	time_t	rez;

	time.tv_sec = time.tv_sec - lastf.tv_sec;
	time.tv_usec = time.tv_usec - lastf.tv_usec;
	rez = (time_t)(time.tv_sec) + (time_t)(time.tv_usec);
	if (rez < die)
		return (0);
	return (1);
}

int	feedcheck(t_main *g_struct)
{
	int	i;

	i = 0;
	while (i < g_struct->input.num_of_phil)
	{
		if (g_struct->phils[i].lunch != 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_status(char *status, t_main *g_struct, int i)
{
	struct timeval		now;
	unsigned long int	timestamp;

	pthread_mutex_lock(&g_struct->report);
	gettimeofday(&now, NULL);
	timestamp = (unsigned long int)((((useconds_t)(now.tv_sec * 1000000) \
	+ now.tv_usec) - g_struct->start) / 1000);
	if (g_struct->is_all_alive == 1 && g_struct->phils[i].lunch != 0)
		printf("%lu %d%s", timestamp, i + 1, status);
	pthread_mutex_unlock(&g_struct->report);
}

void	shut_down(int i, t_main *g_struct)
{
	struct timeval		now;
	unsigned long int	timestamp;

	pthread_mutex_lock(&g_struct->report);
	gettimeofday(&now, NULL);
	timestamp = (unsigned long int)((((useconds_t)(now.tv_sec * 1000000) \
	+ now.tv_usec) - g_struct->start) / 1000);
	printf("%lu %d%s", timestamp, i + 1, DEATH);
}
