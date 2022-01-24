/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:07:00 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:38:33 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	param_r_h(char *tmp, t_mpp *p, int **err, int hi)
{
	p->rezolution[1] = ft_atoi(tmp);
	if (p->rezolution[1] <= 0 || p->rezolution[1] > hi)
		p->rezolution[1] = hi;
	while (ft_isdigit(*tmp))
		tmp++;
	while (*tmp)
	{
		if (!(*tmp == ' ') && !(*tmp == '\t'))
		{
			**err = **err | ERR_1STRING;
			return ;
		}
		tmp++;
	}
}

void	param_r_w(char *tmp, t_mpp *p, int **err, int *r)
{
	tmp = tmp + 1;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (ft_isdigit(*tmp) == 0)
	{
		**err = **err | ERR_1STRING;
		return ;
	}
	p->rezolution[0] = ft_atoi(tmp);
	if (p->rezolution[0] <= 0 || p->rezolution[0] > r[0])
		p->rezolution[0] = r[0];
	while (ft_isdigit(*tmp))
		tmp++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (ft_isdigit(*tmp) == 0)
	{
		**err = **err | ERR_1STRING;
		return ;
	}
	param_r_h(tmp, p, err, r[1]);
}

void	param_txr(char *line, char **dst, int **err, int c)
{
	char	*tmp;
	int		fd;
	int		hm;

	hm = c / 10;
	tmp = line;
	tmp = tmp + hm;
	*dst = ft_strtrim(tmp, " \t");
	fd = open(*dst, O_RDONLY);
	if (fd < 0)
	{
		if (c == 20)
			**err = **err | ERR_2STRING;
		if (c == 21)
			**err = **err | ERR_3STRING;
		if (c == 22)
			**err = **err | ERR_4STRING;
		if (c == 23)
			**err = **err | ERR_5STRING;
		if (c == 10)
			**err = **err | ERR_6STRING;
	}
	close(fd);
}

void	param_fc_s(char *tmp, int *floor, int **err, int i)
{
	floor[3] = 0;
	tmp = tmp + ft_len(floor[1], 10);
	while (*tmp == ' ' || *tmp == '\t' || *tmp == ',')
	{
		if (*tmp == ',')
			floor[3]++;
		tmp++;
	}
	if (ft_isdigit(*tmp) == 0 || floor[3] > 1)
	{
		ft_trashfunc(i, err);
		return ;
	}
	floor[2] = ft_atoi(tmp);
	tmp = tmp + ft_len(floor[2], 10);
	while (*tmp)
	{
		if (!(*tmp == ' ') && !(*tmp == '\t'))
			ft_trashfunc(i, err);
		tmp++;
	}
	if (floor[0] > 255 || floor[1] > 255 || floor[2] > 255)
		ft_trashfunc(i, err);
}

void	param_fc(char *tmp, int *floor, int **err, int i)
{
	floor[3] = 0;
	tmp = tmp + 1;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (ft_isdigit(*tmp) == 0)
	{
		ft_trashfunc(i, err);
		return ;
	}
	floor[0] = ft_atoi(tmp);
	tmp = tmp + ft_len(floor[0], 10);
	while (*tmp == ' ' || *tmp == '\t' || *tmp == ',')
	{
		if (*tmp == ',')
			floor[3]++;
		tmp++;
	}
	if (ft_isdigit(*tmp) == 0 || floor[3] > 1)
	{
		ft_trashfunc(i, err);
		return ;
	}
	floor[1] = ft_atoi(tmp);
	param_fc_s(tmp, floor, err, i);
}
