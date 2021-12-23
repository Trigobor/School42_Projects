/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:22:57 by eosfryd           #+#    #+#             */
/*   Updated: 2021/01/18 21:04:17 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char				*ft_itoa_ll(long long int n)
{
	char			*num;
	long long int	size;
	long long int	first;

	size = 1;
	first = n;
	if (n < 0)
		size++;
	while ((first /= 10) != 0)
		size++;
	if ((num = (char *)malloc((size + 1) * sizeof(char))) == (NULL))
		return (NULL);
	num[size] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		num[--size] = -(n % 10) + '0';
		n = n / -10 + 0 * first++;
	}
	while (--size >= first)
	{
		num[size] = n % 10 + '0';
		n = n / 10;
	}
	return (num);
}
