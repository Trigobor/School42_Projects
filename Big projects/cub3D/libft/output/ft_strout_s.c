/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:12:15 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:03:51 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*what_about_accuracy(t_list_p *ml, const char *argumento)
{
	char		*preret;
	int			len;

	len = (ml->accuracy + 1);
	if ((ml->accuracy < (int)ft_strlen(argumento)) && (ml->accuracy >= 0))
	{
		preret = (char *)malloc(len * sizeof(char));
		if (!(preret))
			return (NULL);
		ft_strlcpy(preret, argumento, len);
	}
	else
		preret = ft_strdup(argumento);
	return (preret);
}

static char	*make_me_some_strings(t_list_p *modlist, const char *argumento)
{
	char		*ret;
	char		*spaaaaace;
	char		*ret_two;
	int			len;

	ret_two = NULL;
	if (argumento == NULL)
		argumento = "(null)";
	ret = what_about_accuracy(modlist, argumento);
	len = ft_strlen(ret);
	if (modlist->width > len)
	{
		spaaaaace = ft_spaaaaace(modlist->width - len, ' ');
		if ((modlist->flag & FLAG_MINUS) == FLAG_MINUS)
			ret_two = ft_strjoin(ret, spaaaaace);
		else
			ret_two = ft_strjoin(spaaaaace, ret);
		free(spaaaaace);
		free(ret);
		return (ret_two);
	}
	return (ret);
}

char	*ft_strout_s(t_list_p *modlist, va_list *arg)
{
	char		*ret;
	const char	*argumento;

	argumento = va_arg(*arg, const char *);
	if (modlist->width < 0)
	{
		modlist->width = -(modlist->width);
		modlist->flag = modlist->flag | FLAG_MINUS;
	}
	ret = make_me_some_strings(modlist, argumento);
	modlist->length = ft_strlen(ret);
	return (ret);
}
