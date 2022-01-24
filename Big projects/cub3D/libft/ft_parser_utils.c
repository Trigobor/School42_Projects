/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:52 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 15:16:32 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_accuracy(const char *s, va_list *pa, int *i)
{
	int	accuracy;
	int	size;

	size = 0;
	if (s[*i] == '.')
	{
		*i = *i + 1;
		if (s[*i] == '*')
		{
			accuracy = va_arg(*pa, int);
			*i = *i + 1;
			if (accuracy < 0)
				return (-1);
			return (accuracy);
		}
		else if (s[*i] >= '0' && s[*i] <= '9')
		{
			while (s[*i + size] >= '0' && s[*i + size] <= '9')
				size++;
			*i = *i + size;
			return (ft_atoi(ft_substr(s, *i - size, size)));
		}
		return (0);
	}
	return (-1);
}

int	ft_flag(const char *s, int *item)
{
	int	flag;

	flag = FLAG_OUT;
	while ((s[*item] == '-') || (s[*item] == '0'))
	{
		if (s[*item] == '-')
			flag = flag | FLAG_MINUS;
		else if (s[*item] == '0')
			flag = flag | FLAG_ZERO;
		else
			return (flag);
		*item = *item + 1;
	}
	return (flag);
}

int	ft_type(const char *s, int *i)
{
	if (s[*i] == 'c')
		return (1);
	if (s[*i] == 's')
		return (2);
	if (s[*i] == 'p')
		return (3);
	if (s[*i] == 'd')
		return (4);
	if (s[*i] == 'i')
		return (5);
	if (s[*i] == 'u')
		return (6);
	if (s[*i] == 'x')
		return (7);
	if (s[*i] == 'X')
		return (8);
	if (s[*i] == '%')
		return (9);
	return (0);
}

int	ft_width(const char *s, va_list *arg, int *i)
{
	int	size;

	size = 0;
	if (s[*i] == '*')
	{
		*i = *i + 1;
		return (va_arg(*arg, int));
	}
	else if (s[*i] >= '0' && s[*i] <= '9')
	{
		while (s[*i] >= '0' && s[*i] <= '9')
		{
			size++;
			*i = *i + 1;
		}
		return (ft_atoi(ft_substr(s, *i - size, size)));
	}
	return (0);
}
