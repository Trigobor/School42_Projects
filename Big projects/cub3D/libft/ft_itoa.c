/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:38:32 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:10:27 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_itoa_main(int n)
{
	char		*rez;
	int			len;
	int			m;

	m = n;
	len = 1;
	len = len + ft_len(m, 10);
	if (n < 0)
		m = 1;
	if (m == 1)
		n = -n;
	rez = (char *)malloc(len + 1 + m);
	if (NULL == rez)
		return (NULL);
	rez[0] = '-';
	rez[len + m] = '\0';
	while (len-- != 0)
	{
		rez[len + m] = (n % 10) + 48;
		n = n / 10;
	}
	return (rez);
}

static	char	*ft_itoa_min(int n)
{
	char		*rez;
	int			len;

	len = 10;
	n /= 10;
	n = -n;
	rez = (char *)malloc(12);
	if (NULL == rez)
		return (NULL);
	rez[len + 1] = '\0';
	rez[len] = '8';
	rez[0] = '-';
	while (len-- != 1)
	{
		rez[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (rez);
}

char	*ft_itoa(int n)
{
	if (n == (-2147483648))
		return (ft_itoa_min(n));
	return (ft_itoa_main(n));
}
