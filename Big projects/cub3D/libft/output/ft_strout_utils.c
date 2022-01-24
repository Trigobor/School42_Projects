/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:12:15 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:01:20 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	itos(char *str, unsigned int n, int i)
{
	if (n % 16 == 10)
		str[i] = 'a';
	else if (n % 16 == 11)
		str[i] = 'b';
	else if (n % 16 == 12)
		str[i] = 'c';
	else if (n % 16 == 13)
		str[i] = 'd';
	else if (n % 16 == 14)
		str[i] = 'e';
	else if (n % 16 == 15)
		str[i] = 'f';
	else
		str[i] = n % 16 + '0';
}

char	*ft_itoa_for_x(unsigned int n)
{
	char	*str;
	int		i;

	i = ft_len(n, 16);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		itos(str, n, i);
		n = n / 16;
		i--;
	}
	return (str);
}

char	*ft_itoa_for_u(unsigned int n, int len)
{
	char	*rez;

	rez = (char *)malloc((len + 1) * sizeof(char));
	if (!(rez))
		return (NULL);
	rez[len] = '\0';
	while (len-- != 0)
	{
		rez[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (rez);
}

char	*ft_spaaaaace(int len, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strout(t_list_p *modlist, va_list *arg)
{
	if (modlist->type == 1)
		return (ft_strout_c(modlist, arg));
	else if (modlist->type == 2)
		return (ft_strout_s(modlist, arg));
	else if (modlist->type == 3)
		return (ft_strout_p(modlist, arg));
	else if (modlist->type == 4 || modlist->type == 5)
		return (ft_strout_d(modlist, arg));
	else if (modlist->type == 6)
		return (ft_strout_u(modlist, arg));
	else if (modlist->type == 7)
		return (ft_strout_x(modlist, arg, 1));
	else if (modlist->type == 8)
		return (ft_strout_x(modlist, arg, 0));
	else if (modlist->type == 9)
		return (ft_strout_percent(modlist));
	return (NULL);
}
