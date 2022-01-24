/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:47:06 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/07 16:41:14 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	finish;
	char	*rez;

	if ((!(s1)) || (!(set)))
		return (NULL);
	start = 0;
	finish = ft_strlen(s1);
	while (ft_strchr(set, s1[start]))
		++start;
	while (ft_strchr(set, s1[finish - 1]) && (start < (finish - 2)))
		--finish;
	if (start < (finish - 1))
	{
		if (!(rez = ft_substr(s1, start, (finish - start))))
			return (NULL);
	}
	else if (!(rez = (char*)ft_calloc(1, sizeof(char))))
		return (NULL);
	return (rez);
}
