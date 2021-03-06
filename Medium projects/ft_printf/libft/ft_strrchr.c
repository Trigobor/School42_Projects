/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:04:47 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/07 15:31:29 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*ss;

	ss = NULL;
	while (*s)
	{
		if (*s == c)
			ss = (char*)s;
		s++;
	}
	if (c != '\0')
		return (ss);
	return (char*)s;
}
