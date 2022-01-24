/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenpluserr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:19:17 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:38:05 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*header(t_all *mains, int *weight)
{
	char	*head;

	*weight = mains->mpp.rezolution[0] * mains->mpp.rezolution[1] * 4;
	head = ft_calloc(sizeof(char), 54);
	if (!head)
		go(101, mains);
	head[0] = (unsigned char)('B');
	head[1] = (unsigned char)('M');
	head[2] = (unsigned char)(54 + *weight);
	head[3] = (unsigned char)((54 + *weight) >> 8);
	head[4] = (unsigned char)((54 + *weight) >> 16);
	head[5] = (unsigned char)((54 + *weight) >> 24);
	head[10] = (unsigned char)(54);
	head[14] = (unsigned char)(40);
	head[18] = (unsigned char)(mains->mpp.rezolution[0]);
	head[19] = (unsigned char)(mains->mpp.rezolution[0] >> 8);
	head[20] = (unsigned char)(mains->mpp.rezolution[0] >> 16);
	head[21] = (unsigned char)(mains->mpp.rezolution[0] >> 24);
	head[22] = (unsigned char)(-mains->mpp.rezolution[1]);
	head[23] = (unsigned char)(-mains->mpp.rezolution[1] >> 8);
	head[24] = (unsigned char)(-mains->mpp.rezolution[1] >> 16);
	head[25] = (unsigned char)(-mains->mpp.rezolution[1] >> 24);
	head[26] = (unsigned char)(1);
	head[28] = (unsigned char)(32);
	return (head);
}

void	bmpcreator(t_all *mains)
{
	int	fd;
	int	weight;

	weight = 0;
	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRWXU);
	write(fd, header(mains, &weight), 54);
	write(fd, (char *)mains->img.adr, weight);
	go(53, mains);
}

int	seconderrmessege(int err, int i)
{
	if (err & ERR_MISPLAY)
		i = i + ft_printf("Отсутствует игрок\n");
	if (err & ERR_TOMPLAY)
		i = i + ft_printf("Слишком много игроков\n");
	if (err & ERR_NOTCHAR)
		i = i + ft_printf("Недопустимые символы карты\n");
	if (err & ERR_NOWALLS)
		i = i + ft_printf("Пробоина в стене\n");
	if (err & ERR_TEXTURE)
		i = i + ft_printf("Непредвиденная ошибка в параметрах карты\n");
	if (err & ERR_EMPLINE)
		i = i + ft_printf("В карте содержится пустая строка\n");
	if (i > 250)
		ft_printf("P.S.\nЭто уже не карта, а кусок дерьма\n");
	else if (i > 200)
		ft_printf("P.S.\nТы ужасный человек\n");
	else if (i > 150)
		ft_printf("P.S.\nТебе должно быть стыдно\n");
	else if (i > 80)
		ft_printf("P.S.\nХватит ломать карту\n");
	return (err);
}

int	errmessege(int err)
{
	int	i;

	i = 0;
	ft_printf("Error\n");
	if (err & ERR_1STRING)
		i = i + ft_printf("Ошибка с разрешением\n");
	if (err & ERR_2STRING)
		i = i + ft_printf("Ошибка с северной текстурой \n");
	if (err & ERR_3STRING)
		i = i + ft_printf("Ошибка с южной текстурой\n");
	if (err & ERR_4STRING)
		i = i + ft_printf("Ошибка с западной текстурой\n");
	if (err & ERR_5STRING)
		i = i + ft_printf("Ошибка с восточной текстурой\n");
	if (err & ERR_6STRING)
		i = i + ft_printf("Ошибка с текстурой спрайта\n");
	if (err & ERR_7STRING)
		i = i + ft_printf("Ошибка с цветом неба\n");
	if (err & ERR_8STRING)
		i = i + ft_printf("Ошибка с цветом пола\n");
	if (err & ERR_READING)
		i = i + ft_printf("Непредвиденная ошибка чтения\n");
	if (err & ERR_TOMANYF)
		i = i + ft_printf("Слишком много аргументов\n");
	return (seconderrmessege(err, i));
}
