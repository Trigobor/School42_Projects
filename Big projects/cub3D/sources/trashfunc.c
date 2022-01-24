/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:23:16 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:37:47 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ana(char *str, int *err)
{
	int		count;
	int		i;

	count = 0;
	i = count;
	while (*str)
	{
		if (*str == '\n')
			count++;
		if (*str != '\n')
		{
			if (count != 0)
				i++;
			if (i > 9 && count > 1)
				*err = *err | ERR_EMPLINE;
			count = 0;
		}
		str++;
	}
}

int	aaa(char **aaa)
{
	int		i;

	i = 0;
	while (aaa[i])
		i++;
	return (i);
}

void	j(char **a, char *b, int *e)
{
	char	*c;

	c = *a;
	*a = ft_strjoin(*a, b);
	if (!(*a))
		*e = *e | ERR_READING;
	free(c);
}

void	ft_trimmer(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 8)
	{
		tmp = ft_strtrim(map[i], " \t");
		free(map[i]);
		map[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
}

char	*ft_add_n(int m, char c, char *s, t_all *mains)
{
	char	*rez;
	char	*tmp;

	tmp = ft_spaaaaace(m + 10 - ft_strlen(s), c);
	if (!(tmp))
		go(101, mains);
	rez = ft_strjoin(s, tmp);
	free(tmp);
	return (rez);
}
