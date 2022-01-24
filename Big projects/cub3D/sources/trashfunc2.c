/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashfunc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:55:38 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:45:19 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(int keycode, t_all *mains)
{
	keycode = 53;
	go(keycode, mains);
	return (0);
}

int	reversestrncmp(char *a, char *b, int n)
{
	int	i;
	int	j;

	i = ft_strlen(a);
	j = ft_strlen(b);
	while (n--)
	{
		if (a[i--] != b[j--])
			return (1);
	}
	return (0);
}

int	ft_height(t_all *mains)
{
	float	factor;
	float	ang;
	int		height;

	ang = fabs((float)mains->ray.count / ((float)mains->win.x / 2) - 1);
	ang = ang * ((FOV / 2) * M_PI / 180);
	factor = mains->hit.d * cos(ang);
	height = round(mains->win.x / factor);
	return (height);
}

void	ft_rdir(t_all *mains)
{
	float	ang;

	ang = (float)mains->ray.count / (mains->win.x / 2) - 1;
	ang = ang * ((FOV / 2) * M_PI / 180);
	mains->ray.x = mains->dir.x * cos(ang) - mains->dir.y * sin(ang);
	mains->ray.y = mains->dir.y * cos(ang) + mains->dir.x * sin(ang);
	if (mains->ray.x >= 0)
		mains->ray.hv = 1;
	else
		mains->ray.hv = 0;
	if (mains->ray.y >= 0)
		mains->ray.hh = 1;
	else
		mains->ray.hh = 0;
}

void	ft_trashfunc(int i, int **err)
{
	if (i == 1)
		**err = **err | ERR_7STRING;
	if (i == 0)
		**err = **err | ERR_8STRING;
}
