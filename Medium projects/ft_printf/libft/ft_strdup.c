/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:49:11 by eosfryd           #+#    #+#             */
/*   Updated: 2020/10/30 16:50:29 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		size;
	int		item;
	int		jtem;
	char	*copy;

	size = 0;
	item = 0;
	jtem = 0;
	while (src[item++])
		size++;
	copy = (char*)malloc((size * sizeof(char)) + 1);
	if (copy == NULL)
		return (NULL);
	while (src[jtem])
	{
		copy[jtem] = src[jtem];
		jtem++;
	}
	copy[jtem] = '\0';
	return (copy);
}
