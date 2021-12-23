/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:10:15 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/07 16:59:05 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	item;
	size_t	jtem;
	char	*rez;

	if (!(s))
		return (NULL);
	item = ft_strlen((char*)s);
	if (item < start)
		len = 0;
	else if ((item - start) < len)
		len = item - start;
	if (!(rez = (char*)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	jtem = 0;
	while ((jtem < len) && (s[jtem]))
		rez[jtem++] = s[start++];
	return (rez);
}
