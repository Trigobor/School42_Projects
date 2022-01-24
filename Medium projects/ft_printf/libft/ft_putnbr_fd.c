/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:57:04 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/07 19:28:05 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	sign;
	int		rev;
	char	rez[42];

	sign = n;
	if (sign < 0)
	{
		write(fd, "-", 1);
		sign = -sign;
	}
	rev = 0;
	if (sign == 0)
		write(fd, "0", 1);
	while (sign != 0)
	{
		rez[rev++] = sign % 10 + '0';
		sign /= 10;
	}
	while (rev--)
		write(fd, rez + rev, 1);
}
