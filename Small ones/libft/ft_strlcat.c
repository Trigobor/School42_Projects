/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:29:44 by eosfryd           #+#    #+#             */
/*   Updated: 2020/10/31 16:58:53 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	j = 0;
	r = ft_strlen(dst);
	if (r >= dstsize)
		return (dstsize + ft_strlen(src));
	while ((dst[i] != '\0') && (i < dstsize - 1))
		i++;
	while ((src[j] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if ((i != dstsize - 1) || (i != dstsize))
		dst[i] = '\0';
	return (ft_strlen(src) + r);
}
