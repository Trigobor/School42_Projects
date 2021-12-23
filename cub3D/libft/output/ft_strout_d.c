/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:12:15 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:09:07 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*make_ret2(t_list_p *m, char *ret, int len, char *sign)
{
	char			*retelse;

	retelse = NULL;
	if (m->accuracy == -1 && ((m->flag & FLAG_ZERO) == FLAG_ZERO))
	{
		retelse = ft_strjoin(ft_spaaaaace(m->width - len, '0'), ret);
		free(ret);
		ret = ft_strjoin(sign, retelse);
		if (!(ret))
			ret = ft_strdup(retelse);
		free(retelse);
	}
	else
	{
		retelse = ft_strjoin(sign, ret);
		if (!(retelse))
			retelse = ft_strdup(ret);
		free(ret);
		if ((m->flag & FLAG_MINUS) == FLAG_MINUS)
			return (ft_strjoin(retelse, ft_spaaaaace(m->width - len, ' ')));
		else
			return (ft_strjoin(ft_spaaaaace(m->width - len, ' '), retelse));
		return (NULL);
	}
	return (ret);
}

static char	*make_ret(char *preret, t_list_p *modlist, char *sign)
{
	char			*ret;
	int				len;

	len = ft_strlen(preret);
	if (sign != NULL)
		len++;
	if (modlist->width > len)
		ret = make_ret2(modlist, preret, len, sign);
	else
	{
		ret = ft_strjoin(sign, preret);
		if (!(ret))
			ret = ft_strdup(preret);
		free(preret);
	}
	return (ret);
}

static char	*make_preret(char *prepreret, t_list_p *modlist, int len)
{
	char			*spaaace;
	char			*ret;

	if (modlist->accuracy > len)
	{
		spaaace = ft_spaaaaace(modlist->accuracy - len, '0');
		ret = ft_strjoin(spaaace, prepreret);
		free(spaaace);
		free(prepreret);
		return (ret);
	}
	return (prepreret);
}

static char	*make_me_some_strings(t_list_p *ml, long int ar)
{
	char			*preret;
	char			*prepreret;
	int				len;
	char			*minus;

	minus = NULL;
	if (ar < 0)
	{
		ar = -ar;
		minus = "-";
	}
	len = ft_len(ar, 10);
	if (ml->accuracy == 0 && ar == 0)
		prepreret = ft_calloc(1, 1);
	else
		prepreret = ft_itoa_ll(ar);
	preret = make_preret(prepreret, ml, len);
	return (make_ret(preret, ml, minus));
}

char	*ft_strout_d(t_list_p *modlist, va_list *arg)
{
	char			*ret;
	int				argumento;

	argumento = va_arg(*arg, int);
	if (modlist->width < 0)
	{
		modlist->width = -(modlist->width);
		modlist->flag = modlist->flag | FLAG_MINUS;
	}
	if ((modlist->flag & FLAG_MINUS) == FLAG_MINUS)
		modlist->flag = modlist->flag & ~FLAG_ZERO;
	ret = make_me_some_strings(modlist, (long int)argumento);
	modlist->length = ft_strlen(ret);
	return (ret);
}
