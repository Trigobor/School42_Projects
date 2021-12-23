/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:45:03 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:38:50 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parcefile(int fd, char **line, char **map, int *err)
{
	int	flag;

	flag = 42;
	while (flag > 1)
	{
		if ((get_next_line(fd, line)) == 0)
			flag = 0;
		j(map, "\n", err);
		j(map, *line, err);
		free(*line);
	}
}

int	parcer(char *argv, t_all *mains)
{
	int		fd;
	int		err;
	char	*line;
	char	*map;

	err = ERR_ALLGOOD;
	map = malloc(1);
	map[0] = '\0';
	fd = open(argv, O_RDONLY);
	parcefile(fd, &line, &map, &err);
	close(fd);
	ana(map, &err);
	mains->map.arr = ft_split(map, '\n');
	free(map);
	if (aaa(mains->map.arr) < 10)
	{
		ft_clean(mains->map.arr);
		return (ERR_READING);
	}
	ft_trimmer(mains->map.arr);
	errors(&err, mains);
	return (err);
}

void	parce_param(t_all *mains)
{
	int		i;
	int		j;
	char	**tmp;
	int		m;

	i = 0;
	j = i;
	m = 0;
	while (mains->map.arr[i])
	{
		if (m < (int)ft_strlen(mains->map.arr[i]) && (i > 7))
			m = ft_strlen(mains->map.arr[i]);
		i++;
	}
	tmp = malloc(sizeof(char *) * (i - 7));
	if (!(tmp))
		go(101, mains);
	i = 8;
	while (mains->map.arr[i])
		tmp[j++] = ft_add_n(m, ' ', mains->map.arr[i++], mains);
	tmp[j] = NULL;
	mains->map.map = tmp;
}

void	parcer_for_sprites(t_all *mains, int i, int j, int count)
{
	while (mains->map.map[i++])
	{
		j = 0;
		while (mains->map.map[i - 1][j])
			if (mains->map.map[i - 1][j++] == '2')
				count++;
	}
	mains->sprt = malloc(sizeof(t_sprt) * count);
	i = 0;
	j = 0;
	mains->nsprite = count;
	count = 0;
	while (mains->map.map[i++])
	{
		j = 0;
		while (mains->map.map[i - 1][j])
		{
			if (mains->map.map[i - 1][j++] == '2')
			{
				mains->sprt[count].y = (float)i - 0.5;
				mains->sprt[count++].x = (float)j - 0.5;
			}
		}
	}
}

void	parparam(char *line, t_mpp *param, int **err)
{
	int	r[2];

	mlx_get_screen_size(&r[0], &r[1]);
	if (!(ft_strncmp("R", line, 1)))
		param_r_w(line, param, err, r);
	else if (!(ft_strncmp("NO", line, 2)))
		param_txr(line, &param->no, err, 20);
	else if (!(ft_strncmp("SO", line, 2)))
		param_txr(line, &param->so, err, 21);
	else if (!(ft_strncmp("WE", line, 2)))
		param_txr(line, &param->we, err, 22);
	else if (!(ft_strncmp("EA", line, 2)))
		param_txr(line, &param->ea, err, 23);
	else if (!(ft_strncmp("S ", line, 2)) || !(ft_strncmp("S\t", line, 2)))
		param_txr(line, &param->s, err, 10);
	else if (!(ft_strncmp("F", line, 1)))
		param_fc(line, param->floor, err, 0);
	else if (!(ft_strncmp("C", line, 1)))
		param_fc(line, param->sky, err, 1);
	else
		**err = **err | ERR_TEXTURE;
}
