/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcpack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:54:35 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 18:00:41 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	filltxradr(t_all *g, int a, int b, int c)
{
	void			*img;

	img = mlx_xpm_file_to_image(g->mlx.ptr, g->mpp.no, \
	&g->mpp.adr.nw, &g->mpp.adr.nh);
	g->mpp.adr.north = (unsigned int *)mlx_get_data_addr(img, &a, &b, &c);
	free(img);
	img = mlx_xpm_file_to_image(g->mlx.ptr, g->mpp.so, \
	&g->mpp.adr.sw, &g->mpp.adr.sh);
	g->mpp.adr.south = (unsigned int *)mlx_get_data_addr(img, &a, &b, &c);
	free(img);
	img = mlx_xpm_file_to_image(g->mlx.ptr, g->mpp.ea, \
	&g->mpp.adr.ew, &g->mpp.adr.eh);
	g->mpp.adr.east = (unsigned int *)mlx_get_data_addr(img, &a, &b, &c);
	free(img);
	img = mlx_xpm_file_to_image(g->mlx.ptr, g->mpp.we, \
	&g->mpp.adr.ww, &g->mpp.adr.wh);
	g->mpp.adr.west = (unsigned int *)mlx_get_data_addr(img, &a, &b, &c);
	free(img);
	img = mlx_xpm_file_to_image(g->mlx.ptr, g->mpp.s, \
	&g->mpp.adr.sprtw, &g->mpp.adr.sprth);
	g->mpp.adr.sprt = (unsigned int *)mlx_get_data_addr(img, &a, &b, &c);
	free(img);
}

void	col(t_all *mains, int start, int height, int steps)
{
	int				x;
	unsigned int	color;

	height = ft_height(mains);
	start = mains->win.x * (mains->win.y - height) / 2;
	if (height > mains->win.y)
		steps = (height - mains->win.y) / 2;
	else
		steps = 0;
	x = mains->ray.count;
	while (x < mains->win.x * mains->win.y)
	{
		color = mains->mpp.skycolor;
		if (x >= start && steps < height)
		{
			color = pixel_txr(mains, steps, height);
			if (!color)
				color = pixel_txr_two(mains, steps, height);
			steps++;
		}
		if (steps == height)
			color = mains->mpp.floorcolor;
		mains->img.adr[x] = color;
		x += mains->win.x;
	}
}

void	hh(t_all *mains, float a, float b, float e)
{
	float			x;
	float			y;

	x = floor(a) + e;
	y = b + (x - a) * (mains->ray.x / mains->ray.y);
	while ((int)floor(y) > 0 && (int)floor(y) < mains->map.j)
	{
		if (mains->map.map[(int)(x - 1 + e)][(int)floor(y)] == ' ')
			break ;
		if (mains->map.map[(int)(x - 1 + e)][(int)floor(y)] == '1')
		{
			if (mains->hit.d > hypot(x - a, y - b))
			{
				mains->hit.x = y;
				mains->hit.y = x;
				mains->hit.d = hypot(x - a, y - b);
			}
			return ;
		}
		x += (2 * e - 1);
		y += (2 * e - 1) * mains->ray.x / mains->ray.y;
	}
}

void	hv(t_all *mains, float a, float b, float e)
{
	float			x;
	float			y;

	x = floor(a) + e;
	y = b + (x - a) * (mains->ray.y / mains->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < mains->map.i)
	{
		if (mains->map.map[(int)floor(y)][(int)(x - 1 + e)] == ' ')
			break ;
		if (mains->map.map[(int)floor(y)][(int)(x - 1 + e)] == '1')
		{
			if (mains->hit.d > hypot(x - a, y - b))
			{
				mains->hit.x = x;
				mains->hit.y = y;
				mains->hit.d = hypot(x - a, y - b);
			}
			return ;
		}
		x += (2 * e - 1);
		y += (2 * e - 1) * mains->ray.y / mains->ray.x;
	}
}

void	drawler(t_all *mains)
{
	int				bits;
	int				size;
	int				finish;

	mains->img.ptr = mlx_new_image(mains->mlx.ptr, mains->win.x, mains->win.y);
	mains->img.adr = (unsigned int *)
		mlx_get_data_addr(mains->img.ptr, &bits, &size, &finish);
	mains->raycast = malloc(sizeof(t_raycast) * mains->win.x);
	if (!mains->raycast)
		go(101, mains);
	while (mains->ray.count < mains->win.x)
	{
		mains->hit.d = 999999;
		ft_rdir(mains);
		hv(mains, mains->pos.x, mains->pos.y, mains->ray.hv);
		hh(mains, mains->pos.y, mains->pos.x, mains->ray.hh);
		mains->raycast[mains->ray.count].x = mains->ray.x;
		mains->raycast[mains->ray.count].y = mains->ray.y;
		mains->raycast[mains->ray.count].d = mains->hit.d;
		col(mains, 0, 0, 0);
		mains->ray.count++;
	}
	ft_sprite(mains, 0, 0);
	free(mains->raycast);
}
