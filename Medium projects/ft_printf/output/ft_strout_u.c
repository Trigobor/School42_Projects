/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:12:15 by eosfryd           #+#    #+#             */
/*   Updated: 2021/01/18 20:37:06 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char			*make_ret2(t_list_p *modlist, char *ret, int len)
{
	char			*retelse;
	char			*nullik;
	char			*spaaaaace;

	retelse = NULL;
	if (modlist->accuracy == -1 &&
	((modlist->flag & FLAG_ZERO) == FLAG_ZERO))
	{
		nullik = ft_spaaaaace(modlist->width - len, '0');
		retelse = ft_strjoin(nullik, ret);
		free(nullik);
		free(ret);
	}
	else
	{
		spaaaaace = ft_spaaaaace(modlist->width - len, ' ');
		if ((modlist->flag & FLAG_MINUS) == FLAG_MINUS)
			retelse = ft_strjoin(ret, spaaaaace);
		else
			retelse = ft_strjoin(spaaaaace, ret);
		free(spaaaaace);
		free(ret);
	}
	return (retelse);
}

static char			*make_ret(char *preret, t_list_p *modlist)
{
	char			*ret;
	int				len;

	len = ft_strlen(preret);
	if (modlist->width > len)
	{
		ret = make_ret2(modlist, preret, len);
		return (ret);
	}
	return (preret);
}

static char			*make_preret(char *prepreret, t_list_p *modlist, int len)
{
	char			*nullik;
	char			*ret;

	if (modlist->accuracy > len)
	{
		nullik = ft_spaaaaace(modlist->accuracy - len, '0');
		ret = ft_strjoin(nullik, prepreret);
		free(nullik);
		free(prepreret);
		return (ret);
	}
	return (prepreret);
}

static char			*make_me_some_strings(t_list_p *ml, unsigned int ar)
{
	char			*ret;
	char			*preret;
	char			*prepreret;
	int				len;

	len = ft_len(ar, 10);
	if (ml->accuracy == 0 && ar == 0)
		prepreret = ft_calloc(1, 1);
	else
		prepreret = ft_itoa_for_u(ar, len);
	preret = make_preret(prepreret, ml, len);
	ret = make_ret(preret, ml);
	return (ret);
}

char				*ft_strout_u(t_list_p *modlist, va_list *arg)
{
	char			*ret;
	unsigned int	argumento;

	argumento = va_arg(*arg, unsigned int);
	if (modlist->width < 0)
	{
		modlist->width = -(modlist->width);
		modlist->flag = modlist->flag | FLAG_MINUS;
	}
	if ((modlist->flag & FLAG_MINUS) == FLAG_MINUS)
		modlist->flag = modlist->flag & ~FLAG_ZERO;
	ret = make_me_some_strings(modlist, argumento);
	modlist->length = ft_strlen(ret);
	return (ret);
}
