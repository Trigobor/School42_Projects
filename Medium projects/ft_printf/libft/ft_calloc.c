/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:20:48 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/06 18:20:08 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*rez;
	size_t	i;

	i = count * size;
	rez = (char *)malloc(i);
	if (NULL == rez)
		return (NULL);
	ft_bzero(rez, i);
	return (rez);
}
