/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:45:49 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:22:32 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	block(t_all *m, int i, int j, int color)
{
	int	x;
	int	y;

	i = i * m->skale;
	j = j * m->skale;
	x = m->skale;
	y = x;
	while (y++ < (2 * m->skale))
	{
		x = (m->skale);
		while (x++ < (2 * m->skale))
			mlx_pixel_put(m->mlx.ptr, m->win.ptr, x + j, y + i, color);
	}
}

static void	folk(t_all *m, int color)
{
	int		x;
	int		y;
	float	i;
	float	j;

	i = m->pos.y * m->skale;
	j = m->pos.x * m->skale;
	x = m->skale + 0.2;
	y = m->skale + 0.2;
	mlx_pixel_put(m->mlx.ptr, m->win.ptr, x + j, y + i, color);
}

void	pr(t_all *m, int x, int y)
{
	while (m->map.map[y])
	{
		x = 0;
		while (m->map.map[y][x])
		{
			if (ft_strchr("0NEWS", m->map.map[y][x]))
				block(m, y, x, 0x817f90);
			if (m->map.map[y][x] == '1')
				block(m, y, x, 0x6a5acd);
			if (m->map.map[y][x] == '2')
				block(m, y, x, 0xC2BBEA);
			x = x + 1;
		}
		y = y + 1;
	}
	folk(m, 0xffff00);
}
