/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:42:07 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 17:52:01 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite(t_all *mains, int i, float a)
{
	if (mains->dir.y <= 0)
		a = acos(mains->dir.x) * 180 / M_PI;
	else
		a = 360 - acos(mains->dir.x) * 180 / M_PI;
	i = 0;
	while (i < mains->nsprite)
	{
		mains->sprt[i].d = hypot(mains->sprt[i].x - mains->pos.x, \
		mains->sprt[i].y - mains->pos.y);
		mains->sprt[i].place = spritep(mains, i, a);
		i++;
	}
	sorts(mains, 0);
	i = 0;
	while (i++ < mains->nsprite)
		popupsprite(mains, mains->sprt[i - 1].place, mains->sprt[i - 1].d, 0);
}

void	ft_new_img(t_all *mains, int i, int tmp)
{
	mains->ray.x = 0;
	mains->ray.y = 0;
	mains->ray.count = 0;
	mains->ray.hv = 0;
	mains->ray.hh = 0;
	mains->hit.x = 0;
	mains->hit.y = 0;
	while (mains->map.map[i])
	{
		mains->map.i = i;
		tmp = ft_strlen(mains->map.map[i]);
		if (tmp > mains->map.j)
			mains->map.j = tmp;
		i++;
	}
	drawler(mains);
	if (mains->bmp == 1)
		bmpcreator(mains);
	mlx_put_image_to_window(mains->mlx.ptr, mains->win.ptr, \
	mains->img.ptr, 0, 0);
	pr(mains, 0, 0);
}

void	game(t_all *mains, int error)
{
	if (error != 0)
	{
		errmessege(error);
		return ;
	}
	fillparam(mains);
	mains->mlx.ptr = mlx_init();
	mains->win.ptr = mlx_new_window(mains->mlx.ptr, mains->win.x, \
	mains->win.y, "Cub3d");
	filltxradr(mains, 0, 0, 0);
	ft_new_img(mains, 0, 0);
	mlx_hook(mains->win.ptr, 2, 1L << 0, go, mains);
	mlx_hook(mains->win.ptr, 17, 0, &ft_close, mains);
	mlx_loop(mains->mlx.ptr);
}

void	fillparam(t_all *mains)
{
	mains->win.x = mains->mpp.rezolution[0];
	mains->win.y = mains->mpp.rezolution[1];
	mains->skale = floor(mains->mpp.rezolution[1] / 100);
	mains->win.ptr = 0;
	mains->mlx.ptr = 0;
	mains->img.ptr = 0;
	mains->img.adr = 0;
	mains->map.sprt_num = 0;
	mains->sprt = 0;
	mains->raycast = 0;
	mains->mpp.floorcolor = (mains->mpp.floor[0] << 16) | \
	(mains->mpp.floor[1] << 8) | (mains->mpp.floor[2]);
	mains->mpp.skycolor = (mains->mpp.sky[0] << 16) | \
	(mains->mpp.sky[1] << 8) | (mains->mpp.sky[2]);
	parce_param(mains);
	parcer_for_sprites(mains, 0, 0, 0);
}

int	main(int argc, char **argv)
{
	t_all			mains;
	int				launch;
	int				a;
	int				f;

	a = 0;
	mains.bmp = 0;
	while (argv[a] && reversestrncmp(argv[a], ".cub", 4) != 0)
		a++;
	launch = 0;
	if (argc < 2)
		return (ft_printf("Error\nСлишком мало аргументов\n"));
	if (!(argv[a]) || reversestrncmp(argv[a], ".cub", 4) != 0)
		return (ft_printf("Error\nНечитаемая карта\n"));
	f = open(argv[a], O_RDONLY);
	if (f < 0)
		return (ft_printf("Error\nНечитаемая карта\n"));
	close(f);
	if (argc > 2 && !(argc == 3 && ft_strcmp(argv[2], "--save") == 0 && a == 1))
		launch = ERR_TOMANYF;
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		mains.bmp = 1;
	launch = launch | parcer(argv[a], &mains);
	game(&mains, launch);
	return (0);
}
