/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:33:12 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/07 19:50:49 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	long int	rez;
	int			znak;

	znak = -1;
	rez = 0;
	while ((*str == ' ') || (*str == '\n') || (*str == '\f')
			|| (*str == '\t') || (*str == '\v') || (*str == '\r'))
		str++;
	if (*str == '-')
		znak = 0;
	if ((*str == '+') || (*str == '-'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		rez = ((rez * 10) + (*str++ - '0'));
		if (rez < 0)
			return (znak);
	}
	if (znak == 0)
		return (int)(rez * -1);
	return (int)(rez);
}
