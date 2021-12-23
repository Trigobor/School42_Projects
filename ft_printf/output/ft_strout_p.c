/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:12:15 by eosfryd           #+#    #+#             */
/*   Updated: 2021/01/18 20:37:47 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int					ft_len(long long int argumento, int i)
{
	int				len;

	len = 1;
	if (argumento == 0)
		return (len);
	while (argumento != 0)
	{
		argumento = argumento / i;
		len++;
	}
	return (len - 1);
}

static void			make_pointer(char *ret, long long int argumento, int len)
{
	ret[0] = '0';
	ret[1] = 'x';
	ret[len] = '\0';
	len--;
	while (ret[len] != 'x')
	{
		if (argumento % 16 == 10)
			ret[len] = 'a';
		else if (argumento % 16 == 11)
			ret[len] = 'b';
		else if (argumento % 16 == 12)
			ret[len] = 'c';
		else if (argumento % 16 == 13)
			ret[len] = 'd';
		else if (argumento % 16 == 14)
			ret[len] = 'e';
		else if (argumento % 16 == 15)
			ret[len] = 'f';
		else
			ret[len] = argumento % 16 + '0';
		argumento = argumento / 16;
		len--;
	}
}

static char			*show_pointer(t_list_p *modlist, long long int argumento)
{
	char			*ret;
	char			*spaaaaace;
	char			*ret_two;
	int				len;

	len = 2;
	if (!(modlist->accuracy > -1 && argumento == (long long int)NULL))
		len = len + ft_len(argumento, 16);
	if (!(ret = (char*)malloc((len + 1) * (sizeof(char)))))
		return (NULL);
	make_pointer(ret, argumento, len);
	if (len < modlist->width)
	{
		spaaaaace = ft_spaaaaace(modlist->width - (len), ' ');
		if ((modlist->flag & FLAG_MINUS) == FLAG_MINUS)
			ret_two = ft_strjoin(ret, spaaaaace);
		else
			ret_two = ft_strjoin(spaaaaace, ret);
		free(spaaaaace);
		return (ret_two);
	}
	return (ret);
}

char				*ft_strout_p(t_list_p *modlist, va_list *arg)
{
	char			*ret;
	long long int	argumento;

	argumento = va_arg(*arg, long long int);
	if (modlist->width < 0)
	{
		modlist->width = -(modlist->width);
		modlist->flag = modlist->flag | FLAG_MINUS;
	}
	ret = show_pointer(modlist, argumento);
	modlist->length = ft_strlen(ret);
	return (ret);
}
