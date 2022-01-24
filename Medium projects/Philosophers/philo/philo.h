/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:33:38 by eosfryd           #+#    #+#             */
/*   Updated: 2021/10/24 17:02:42 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define DEATH	" died\n"
# define FEAST	" is eating\n"
# define SLEEP	" is sleeping\n"
# define THINK	" is thinking\n"
# define KEEPS	" has taken a fork\n"
# define SPEED	"\033[31m"
# define MONEY	"\033[33m"
# define LUCKY	"\033[34m"
# define ACTUAL	SPEED
# define COLOR	"\033[m"

typedef struct s_fork
{
	int				count;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_phil
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				count;
	int				meals;
	int				sleep;
	int				lunch;
	struct timeval	lastf;
	useconds_t		flast;
	struct s_main	*main;
	t_fork			*left;
	t_fork			*right;
}	t_phil;

typedef struct s_args
{
	long long int	num_of_phil;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_nap;
	long long int	num_of_eats;
}	t_args;

typedef struct s_main
{
	useconds_t		start;
	t_args			input;
	t_phil			*phils;
	t_fork			*forks;
	pthread_mutex_t	report;
	int				is_all_empty;
	int				is_all_alive;
}	t_main;

/* parce */
int		read_args(int c, char **v, t_args *input);

/* utils */
void	ms_sleep(useconds_t usec);

/* chekers */
int		lifecheck(struct timeval time, struct timeval lastf, int die);
int		feedcheck(t_main *g_struct);

/* stuff */
void	philo_clean(t_main *g_struct);
void	print_status(char *status, t_main *g_struct, int i);
void	shut_down(int i, t_main *g_struct);

#endif
