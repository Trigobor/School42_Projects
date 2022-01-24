/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:03:08 by eosfryd           #+#    #+#             */
/*   Updated: 2021/01/18 20:29:15 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_write(const char *s, int *len, int *item)
{
	while (s[*item] != '%' && s[*item])
	{
		*len = *len + 1;
		write(1, &s[*item], 1);
		*item = *item + 1;
	}
	return ;
}

static t_list_p	*ft_modlist(char *s, t_list_p *m, int *i, va_list *a)
{
	*i = *i + 1;
	m->flag = ft_flag(s, i);
	m->width = ft_width(s, a, i);
	m->accuracy = ft_accuracy(s, a, i);
	m->type = ft_type(s, i);
	return (m);
}

static int		ft_parcer(char *s, va_list *arg, t_list_p *modlist)
{
	int			len;
	int			item;
	char		*str;

	len = 0;
	item = 0;
	while (s[item])
	{
		if (s[item] != '%')
			ft_write(s, &len, &item);
		if (s[item] == '%')
			modlist = ft_modlist(s, modlist, &item, arg);
		if (s[item] == '\0')
			return (len);
		str = ft_strout(modlist, arg);
		len = len + modlist->length;
		ft_putstr_fd(str, 1);
		free(str);
		item++;
	}
	return (len);
}

static int		ft_parcer_interface(char *s, va_list *arg)
{
	int			len;
	t_list_p	*modlist;

	if (!(modlist = (t_list_p*)malloc(sizeof(t_list_p))))
	{
		va_end(*arg);
		return (-1);
	}
	len = ft_parcer(s, arg, modlist);
	free(modlist);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	int			rez;

	va_start(arg, format);
	rez = ft_parcer_interface((char*)format, &arg);
	if (rez == -1)
		return (-1);
	va_end(arg);
	return (rez);
}
