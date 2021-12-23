/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:14:39 by eosfryd           #+#    #+#             */
/*   Updated: 2021/01/18 20:53:35 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define B0000_0000 0
# define B0000_0001 1
# define B0000_0010 2
# define B0000_0100 4
# define B0000_1000 8
# define FLAG_OUT B0000_0000
# define FLAG_MINUS B0000_0001
# define FLAG_PLUS B0000_0010
# define FLAG_ZERO B0000_1000

typedef	struct	s_list_p
{
	int			flag;
	int			width;
	int			accuracy;
	int			type;
	int			length;
}				t_list_p;

int				ft_len(long long int argumento, int i);
int				ft_flag(const char *s, int *item);
int				ft_width(const char *s, va_list *arg, int *i);
int				ft_accuracy(const char *s, va_list *arg, int *i);
int				ft_specifier(const char *s, int *i);
int				ft_type(const char *s, int *i);
char			*ft_itoa_ll(long long int n);
char			*ft_strout(t_list_p *modlist, va_list *arg);
char			*ft_strout_c(t_list_p *modlist, va_list *arg);
char			*ft_strout_s(t_list_p *modlist, va_list *arg);
char			*ft_strout_p(t_list_p *modlist, va_list *arg);
char			*ft_strout_d(t_list_p *modlist, va_list *arg);
char			*ft_strout_u(t_list_p *modlist, va_list *arg);
char			*ft_strout_x(t_list_p *modlist, va_list *arg, int registro);
char			*ft_strout_percent(t_list_p *modlist);
char			*ft_spaaaaace(int len, char c);
char			*ft_itoa_for_u(unsigned int n, int len);
char			*ft_itoa_for_x(unsigned int n);

#endif
