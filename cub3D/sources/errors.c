/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:01:14 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:40:06 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	errwalls(int **err, char **map, int size)
{
	int		v;
	int		h;

	v = 9;
	while (v != (size - 1))
	{
		h = 0;
		while (map[v][h])
		{
			if (ft_strchr("20NEWS", map[v][h]) && ((!(ft_strchr("120NEWS", map[v][h - 1]))) || \
			(!(ft_strchr("120NEWS", map[v][h + 1]))) || (!(ft_strchr("120NEWS", map[v - 1][h]))) || \
			(!(ft_strchr("120NEWS", map[v + 1][h]))) || (!(ft_strchr("120NEWS", map[v - 1][h - 1]))) || \
			(!(ft_strchr("120NEWS", map[v + 1][h + 1]))) || (!(ft_strchr("120NEWS", map[v + 1][h - 1]))) || \
			(!(ft_strchr("120NEWS", map[v - 1][h + 1]))) || (h == 0) || !(map[v][h + 1]) || !(map[v + 1][h + 1]) || \
			!(map[v - 1][h + 1])))
				**err = **err | ERR_NOWALLS;
			h++;
		}
		v++;
	}
	if (ft_strchr(map[v], '0') || ft_strchr(map[v], 'N') || ft_strchr(map[v], 'E') || \
	ft_strchr(map[v], 'W') || ft_strchr(map[v], 'S') || ft_strchr(map[v], '2'))
		**err = **err | ERR_NOWALLS;
}

static void	errplayer(int **err, t_all *mains, int flag)
{
	int		v;
	int		h;

	v = 8;
	while (mains->map.arr[v])
	{
		h = 0;
		while (mains->map.arr[v][h])
		{
			if (ft_strchr("NEWS", mains->map.arr[v][h]))
			{
				flag++;
				mains->pos.x = h;
				mains->pos.y = v - 8;
				pp(mains->map.arr[v][h], mains);
			}
			h++;
		}
		v++;
	}
	if (flag == 0)
		**err = **err | ERR_MISPLAY;
	if (flag > 1)
		**err = **err | ERR_TOMPLAY;
}

static void	errstring(int **err, char *line, int i, t_all *mains)
{
	if (i < 8)
		parparam(line, &mains->mpp, err);
	if ((i == 8) && !(**err & ERR_TEXTURE) && (ft_strchr(line, '0') || \
	ft_strchr(line, '2') || ft_strchr(line, 'N') || ft_strchr(line, 'E') || \
	ft_strchr(line, 'W') || ft_strchr(line, 'S')))
		**err = **err | ERR_NOWALLS;
	if (i > 9)
	{
		i = 0;
		while (line[i])
			if (!(ft_strchr("120 NEWS", line[i++])))
				**err = **err | ERR_NOTCHAR;
	}
}

void	errors(int *err, t_all *mains)
{
	int	size;

	size = 0;
	while (mains->map.arr[size])
	{
		errstring(&err, mains->map.arr[size], size, mains);
		size++;
	}
	errplayer(&err, mains, 0);
	errwalls(&err, mains->map.arr, size);
}
