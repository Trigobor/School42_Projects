/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:12:15 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 16:04:37 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*show_percent(t_list_p *modlist, char *per)
{
	char	*ret;
	char	*nullik;
	char	*spaaaaace;

	if (modlist->width > 1)
	{
		nullik = ft_spaaaaace(modlist->width - 1, '0');
		spaaaaace = ft_spaaaaace(modlist->width - 1, ' ');
		if ((modlist->flag & FLAG_MINUS) == FLAG_MINUS)
			ret = ft_strjoin(per, spaaaaace);
		else if ((modlist->flag & FLAG_ZERO) == FLAG_ZERO)
			ret = ft_strjoin(nullik, per);
		else
			ret = ft_strjoin(spaaaaace, per);
		free(per);
		free(nullik);
		free(spaaaaace);
		return (ret);
	}
	return (per);
}

char	*ft_strout_percent(t_list_p *modlist)
{
	char	*ret;
	char	*percent;

	if (modlist->width < 0)
	{
		modlist->width = -(modlist->width);
		modlist->flag = modlist->flag | FLAG_MINUS;
	}
	percent = (char *)malloc(2 * sizeof(char));
	if (!(percent))
		return (NULL);
	percent[0] = 37;
	percent[1] = '\0';
	ret = show_percent(modlist, percent);
	modlist->length = ft_strlen(ret);
	return (ret);
}
