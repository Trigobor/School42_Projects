/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_str_by_adress.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:39:34 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 15:40:08 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean_str_by_adress(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}
