/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:45:15 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/28 17:03:05 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void		ft_clean(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

static char		*oddo(char **odd, char **line)
{
	char		*new;

	new = NULL;
	if (*odd)
	{
		if ((new = ft_strchr(*odd, '\n')))
		{
			*new = '\0';
			*line = ft_strdup(*odd);
			*odd = ft_strcpy(*odd, ++new);
		}
		else
		{
			*line = ft_strdup(*odd);
			*odd[0] = '\0';
		}
	}
	else
	{
		if ((*line = (char *)malloc(sizeof(char))))
			*line[0] = '\0';
	}
	return (new);
}

static int		ft_return(int hmc, char **line, char *new, char **odd)
{
	if (hmc < 0 || !(*line))
	{
		ft_clean(odd);
		ft_clean(line);
		return (-1);
	}
	else if (hmc || new)
		return (1);
	else
	{
		ft_clean(odd);
		return (0);
	}
}

static char		*newline(char *buff, char **odd)
{
	char		*new;

	new = NULL;
	if ((new = ft_strchr(buff, '\n')))
	{
		*new = '\0';
		ft_clean(odd);
		*odd = ft_strdup(++new);
	}
	return (new);
}

int				get_next_line(int fd, char **line)
{
	int			hmc;
	char		buff[BUFFER_SIZE + 1];
	char		*new;
	char		*cl;
	static char	*odd[1024];

	hmc = 0;
	if ((fd < 0) || !(line) || (BUFFER_SIZE <= 0))
		return (-1);
	new = oddo(&odd[fd], line);
	if (!(*line))
	{
		ft_clean(&odd[fd]);
		return (-1);
	}
	while (!new && (hmc = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[hmc] = '\0';
		new = newline(buff, &odd[fd]);
		cl = *line;
		*line = ft_strjoin(*line, buff);
		free(cl);
	}
	return (ft_return(hmc, line, new, &odd[fd]));
}
