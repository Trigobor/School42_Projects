/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_parce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:59:26 by eosfryd           #+#    #+#             */
/*   Updated: 2021/10/22 16:56:57 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* utils */

useconds_t	timeval_to_useconds_t(struct timeval *time)
{
	return ((useconds_t)(time->tv_sec * 1000000) + time->tv_usec);
}

void	ms_sleep(useconds_t usec)
{
	struct timeval	start;
	struct timeval	now;

	usec *= 1000;
	gettimeofday(&now, NULL);
	start = now;
	while ((timeval_to_useconds_t(&now) - timeval_to_useconds_t(&start)) < usec)
	{
		usleep(25);
		gettimeofday(&now, NULL);
	}
}

long long int	read_arg(const char *str)
{
	long long int	rez;
	int				i;

	i = 0;
	rez = 0;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			rez = ((rez * 10) + (str[i] - '0'));
			if (rez > INT_MAX || rez < INT_MIN)
				return (2147483648);
		}
		else
			return (2147483648);
		i++;
	}
	if (str[0] == '-')
		return (2147483648);
	return (rez);
}

/* parce */

int	check_args(t_args *a)
{
	long long int	err;

	err = 2147483648;
	if ((a->num_of_phil == err || a->num_of_phil <= 0) || \
	(a->time_to_die == err || a->time_to_die <= 0) || \
	(a->time_to_eat == err || a->time_to_eat <= 0) || \
	(a->time_to_nap == err || a->time_to_nap <= 0) || \
	(a->num_of_eats == err || a->num_of_eats == 0))
	{
		printf("wrong argument(s)\n%s", COLOR);
		return (1);
	}
	if (a->num_of_phil == 1)
	{
		printf("0 1 has taken a fork\n");
		ms_sleep(a->time_to_die);
		printf("%lld 1 died\n%s", a->time_to_die, COLOR);
		return (1);
	}
	return (0);
}

int	read_args(int c, char **v, t_args *input)
{
	if (c < 5 || c > 6 || !v)
	{
		printf("wrong argument(s)\n%s", COLOR);
		return (0);
	}
	input->num_of_phil = read_arg(v[1]);
	input->time_to_die = read_arg(v[2]);
	input->time_to_eat = read_arg(v[3]);
	input->time_to_nap = read_arg(v[4]);
	input->num_of_eats = -1;
	if (c == 6)
		input->num_of_eats = read_arg(v[5]);
	if (check_args(input) == 1)
		return (0);
	return (1);
}
