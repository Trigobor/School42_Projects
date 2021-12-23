/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:09:25 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/09 16:10:28 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*rez;

	rez = malloc(sizeof(t_list));
	if (rez == NULL)
		return (NULL);
	rez->next = NULL;
	rez->content = content;
	return (rez);
}
