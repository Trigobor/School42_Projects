/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:12:15 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:12:10 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	option1(char wp, t_list_p *modlist)
{
	char		*spaaaaace;

	spaaaaace = NULL;
	ft_putchar_fd(wp, 1);
	if ((modlist->width) > 1)
	{
		spaaaaace = ft_spaaaaace(modlist->width - 1, ' ');
		ft_putstr_fd(spaaaaace, 1);
		modlist->length = ft_strlen(spaaaaace) + 1;
		free(spaaaaace);
	}
	else
		modlist->length = 1;
}

static void	option2(char wp, t_list_p *modlist)
{
	char		*spaaaaace;

	spaaaaace = NULL;
	if (modlist->width > 1)
	{
		spaaaaace = ft_spaaaaace(modlist->width - 1, ' ');
		ft_putstr_fd(spaaaaace, 1);
		modlist->length = ft_strlen(spaaaaace) + 1;
		free(spaaaaace);
	}
	else
		modlist->length = 1;
	ft_putchar_fd(wp, 1);
}

char	*ft_strout_c(t_list_p *modlist, va_list *arg)
{
	char		*str;
	char		wp;

	str = NULL;
	wp = va_arg(*arg, int);
	if (modlist->width < 0)
	{
		modlist->width = -(modlist->width);
		modlist->flag = modlist->flag | FLAG_MINUS;
	}
	if (modlist->width != 0)
	{
		if ((modlist->flag & FLAG_MINUS) == FLAG_MINUS)
			option1(wp, modlist);
		else
			option2(wp, modlist);
	}
	else
	{
		ft_putchar_fd(wp, 1);
		modlist->length = 1;
	}
	return (str);
}
