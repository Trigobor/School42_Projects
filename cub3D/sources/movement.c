/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:25:31 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 17:27:00 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	go_for(t_all *mains)
{
	mains->pos.x = mains->pos.x + (mains->dir.x * STEP);
	mains->pos.y = mains->pos.y + (mains->dir.y * STEP);
	if ((mains->map.map[(int)floor(mains->pos.y)][(int)floor(mains->pos.x)] == '1') || \
	(mains->map.map[(int)floor(mains->pos.y)][(int)floor(mains->pos.x)] == '2'))
	{
		go_bac(mains);
		return (0);
	}
	return (1);
}

int	go_bac(t_all *mains)
{
	mains->pos.x = mains->pos.x - (mains->dir.x * STEP);
	mains->pos.y = mains->pos.y - (mains->dir.y * STEP);
	if (mains->map.map[(int)floor(mains->pos.y)][(int)floor(mains->pos.x)] == '1' || \
	mains->map.map[(int)floor(mains->pos.y)][(int)floor(mains->pos.x)] == '2')
	{
		go_for(mains);
		return (0);
	}
	return (1);
}

int	go_rig(t_all *mains)
{
	mains->pos.x = mains->pos.x - (mains->dir.y * STEP);
	mains->pos.y = mains->pos.y + (mains->dir.x * STEP);
	if (mains->map.map[(int)floor(mains->pos.y)][(int)floor(mains->pos.x)] == '1' || \
	mains->map.map[(int)floor(mains->pos.y)][(int)floor(mains->pos.x)] == '2')
	{
		go_lef(mains);
		return (0);
	}
	return (1);
}

int	go_lef(t_all *mains)
{
	mains->pos.x = mains->pos.x + (mains->dir.y * STEP);
	mains->pos.y = mains->pos.y - (mains->dir.x * STEP);
	if (mains->map.map[(int)floor(mains->pos.y)][(int)floor(mains->pos.x)] == '1' || \
	mains->map.map[(int)floor(mains->pos.y)][(int)floor(mains->pos.x)] == '2')
	{
		go_rig(mains);
		return (0);
	}
	return (1);
}

int	go(int keycode, t_all *m)
{
	int	a;

	a = 1;
	if (keycode == 13)
		a = go_for(m);
	if (keycode == 1)
		a = go_bac(m);
	if (keycode == 2)
		a = go_rig(m);
	if (keycode == 0)
		a = go_lef(m);
	if (keycode == 124)
		a = rig_cam(m);
	if (keycode == 123)
		a = lef_cam(m);
	if (keycode == 53)
		exit(0);
	if (keycode == 101)
	{
		ft_printf("Error\nПроизошел тролленг\n");
		exit(0);
	}
	ft_new_img(m, 0, 0);
	return (0);
}
