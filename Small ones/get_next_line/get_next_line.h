/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:52:20 by eosfryd           #+#    #+#             */
/*   Updated: 2020/11/25 20:10:22 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_bzero(void *dest, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, char *src);

#endif
