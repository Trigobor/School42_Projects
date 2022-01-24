/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionwork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:30:00 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:40:15 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pp(char chr, t_all *mains)
{
	if (chr == 'E' || chr == 'W')
		mains->dir.x = 1;
	else
		mains->dir.x = 0;
	if (chr == 'W')
		mains->dir.x *= -1;
	else
		mains->dir.x *= 1;
	if (chr == 'S' || chr == 'N')
		mains->dir.y = 1;
	else
		mains->dir.y = 0;
	if (chr == 'N')
		mains->dir.y *= -1;
	else
		mains->dir.y *= 1;
}

int	rig_cam(t_all *mains)
{
	mains->dir.x = mains->dir.x * cos(STEP_CAM) - mains->dir.y * sin(STEP_CAM);
	mains->dir.y = mains->dir.y * cos(STEP_CAM) + mains->dir.x * sin(STEP_CAM);
	mains->dir.x /= hypot(mains->dir.x, mains->dir.y);
	mains->dir.y /= hypot(mains->dir.x, mains->dir.y);
	return (1);
}

int	lef_cam(t_all *mains)
{
	mains->dir.x = mains->dir.x * cos(STEP_CAM) + mains->dir.y * sin(STEP_CAM);
	mains->dir.y = mains->dir.y * cos(STEP_CAM) - mains->dir.x * sin(STEP_CAM);
	mains->dir.x /= hypot(mains->dir.x, mains->dir.y);
	mains->dir.y /= hypot(mains->dir.x, mains->dir.y);
	return (1);
}
