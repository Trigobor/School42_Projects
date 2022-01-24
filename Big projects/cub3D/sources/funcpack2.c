/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcpack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:18:09 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 17:59:46 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	pixel_txr(t_all *mains, int s, int h)
{
	int				pixel;
	float			i;

	i = (float)s / (float)h;
	if (floor(mains->hit.y) == mains->hit.y)
	{
		if (mains->ray.hh == 1)
		{
			pixel = mains->mpp.adr.sw * floor(mains->mpp.adr.sh * i) + \
			mains->mpp.adr.sh * (mains->hit.x - floor(mains->hit.x));
			return (mains->mpp.adr.south[pixel]);
		}
		if (mains->ray.hh == 0)
		{
			pixel = mains->mpp.adr.nw * floor(mains->mpp.adr.nh * i) + \
			mains->mpp.adr.nh * (mains->hit.x - floor(mains->hit.x));
			return (mains->mpp.adr.north[pixel]);
		}
	}
	return ((unsigned int) NULL);
}

unsigned int	pixel_txr_two(t_all *mains, int s, int h)
{
	int				pixel;
	float			i;

	i = (float)s / (float)h;
	if (floor(mains->hit.x) == mains->hit.x)
	{
		if (mains->ray.hv == 1)
		{
			pixel = mains->mpp.adr.ww * floor(mains->mpp.adr.wh * i) + \
			mains->mpp.adr.wh * (mains->hit.y - floor(mains->hit.y));
			return (mains->mpp.adr.west[pixel]);
		}
		if (mains->ray.hv == 0)
		{
			pixel = mains->mpp.adr.ew * floor(mains->mpp.adr.eh * i) + \
			mains->mpp.adr.eh * (mains->hit.y - floor(mains->hit.y));
			return (mains->mpp.adr.east[pixel]);
		}
	}
	return (0xFF00FF);
}

void	popupsprite(t_all *mains, int place, float spr_d, float size)
{
	unsigned int	pixel;
	unsigned int	id;
	int				i;
	int				j;

	size = mains->win.x / spr_d;
	place = place - size / 2;
	i = 0;
	while (i < size)
	{
		j = 0;
		while ((place + i >= 0 && place + i < mains->win.x) && \
		(j < size && mains->raycast[place + i].d > spr_d))
		{
			pixel = mains->mpp.adr.sprtw * floor(mains->mpp.adr.sprth * \
			(float)j / size) + mains->mpp.adr.sprth * (float)i / size;
			pixel = mains->mpp.adr.sprt[pixel];
			id = place + i + (mains->win.y / 2 - \
			floor(size / 2) + j++) * mains->win.x;
			if (id < (unsigned int)(mains->win.x * \
			mains->win.y) && pixel != 0xFF000000)
				mains->img.adr[id] = pixel;
		}
		i++;
	}
}

int	spritep(t_all *mains, int i, float a)
{
	float			x;
	float			y;

	x = (mains->sprt[i].x - mains->pos.x) / mains->sprt[i].d;
	y = (mains->sprt[i].y - mains->pos.y) / mains->sprt[i].d;
	if (y <= 0)
		a = FOV / 2 + a - (acos(x) * 180 / M_PI);
	else
		a = FOV / 2 + a - (360 - acos(x) * 180 / M_PI);
	if (a >= 180)
		a -= 360;
	if (a <= -180)
		a += 360;
	return ((a / FOV) * mains->win.x);
}

void	sorts(t_all *mains, int i)
{
	t_sprt			tmp;

	while (i < mains->nsprite - 1)
	{
		if (mains->sprt[i].d < mains->sprt[i + 1].d)
		{
			tmp = mains->sprt[i];
			mains->sprt[i] = mains->sprt[i + 1];
			mains->sprt[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}
