/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:07:36 by eosfryd           #+#    #+#             */
/*   Updated: 2021/04/13 17:42:06 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h> 
# include "../libft/libft.h"
# include "../libmlx/mlx.h"

# define E0000_0000_0000_0000 0
# define E0000_0000_0000_0001 1
# define E0000_0000_0000_0010 2
# define E0000_0000_0000_0100 4
# define E0000_0000_0000_1000 8
# define E0000_0000_0001_0000 16
# define E0000_0000_0010_0000 32
# define E0000_0000_0100_0000 64
# define E0000_0000_1000_0000 128
# define E0000_0001_0000_0000 256
# define E0000_0010_0000_0000 512
# define E0000_0100_0000_0000 1024
# define E0000_1000_0000_0000 2048
# define E0001_0000_0000_0000 4096
# define E0010_0000_0000_0000 8192
# define E0100_0000_0000_0000 16384
# define E1000_0000_0000_0000 32768

# define ERR_ALLGOOD E0000_0000_0000_0000
# define ERR_1STRING E0000_0000_0000_0001
# define ERR_2STRING E0000_0000_0000_0010
# define ERR_3STRING E0000_0000_0000_0100
# define ERR_4STRING E0000_0000_0000_1000
# define ERR_5STRING E0000_0000_0001_0000
# define ERR_6STRING E0000_0000_0010_0000
# define ERR_7STRING E0000_0000_0100_0000
# define ERR_8STRING E0000_0000_1000_0000
# define ERR_READING E0000_0001_0000_0000
# define ERR_TOMANYF E0000_0010_0000_0000
# define ERR_EMPLINE E0000_0100_0000_0000
# define ERR_MISPLAY E0000_1000_0000_0000
# define ERR_TOMPLAY E0001_0000_0000_0000
# define ERR_NOTCHAR E0010_0000_0000_0000
# define ERR_NOWALLS E0100_0000_0000_0000
# define ERR_TEXTURE E1000_0000_0000_0000

# define SKALE 10
# define STEP 0.3
# define STEP_CAM 0.1
# define FOV 60

typedef struct s_win
{
	void	*ptr;
	int		x;
	int		y;
}				t_win;

typedef struct s_mlx
{
	void	*ptr;
}				t_mlx;

typedef struct s_img
{
	void			*ptr;
	unsigned int	*adr;
}				t_img;

typedef struct s_map
{
	char	**arr;
	char	**map;
	int		x;
	int		y;
	int		sprt_num;
	int		i;
	int		j;
}				t_map;

typedef struct s_pos
{
	float	x;
	float	y;
}				t_pos;

typedef struct s_txradress
{
	unsigned int	*north;
	int				nw;
	int				nh;
	unsigned int	*south;
	int				sw;
	int				sh;
	unsigned int	*east;
	int				ew;
	int				eh;
	unsigned int	*west;
	int				ww;
	int				wh;
	unsigned int	*sprt;
	int				sprtw;
	int				sprth;
}				t_txradress;

typedef struct s_sprt
{
	float	x;
	float	y;
	float	d;
	int		place;
	int		visible;
}				t_sprt;

typedef struct s_dir
{
	float	x;
	float	y;
	float	a;
}				t_dir;

typedef struct s_ray
{
	float	x;
	float	y;
	int		count;
	float	hv;
	float	hh;
	float	xx;
	float	yy;
}				t_ray;

typedef struct s_hit
{
	float	x;
	float	y;
	float	d;
}				t_hit;

typedef struct s_raycast
{
	float	x;
	float	y;
	float	d;
}				t_raycast;

typedef struct s_mpp
{
	int			rezolution[2];
	int			floor[4];
	int			sky[4];
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*s;
	int			floorcolor;
	int			skycolor;
	t_txradress	adr;
}				t_mpp;

typedef struct s_all
{
	int			nsprite;
	int			skale;
	int			bmp;

	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_map		map;
	t_pos		pos;
	t_dir		dir;
	t_ray		ray;
	t_hit		hit;
	t_sprt		*sprt;
	t_raycast	*raycast;
	t_mpp		mpp;
}				t_all;

int				go_bac(t_all *mains);
int				go_for(t_all *mains);
int				go_lef(t_all *mains);
int				go_rig(t_all *mains);
int				go(int keycode, t_all *m);
int				rig_cam(t_all *mains);
int				lef_cam(t_all *mains);

int				parcer(char *argv, t_all *mains);
void			parce_param(t_all *mains);
void			parcer_for_sprites(t_all *mains, int i, int j, int count);
void			pp(char chr, t_all *mains);
void			fillparam(t_all *mains);
void			parparam(char *line, t_mpp *param, int **err);

void			pr(t_all *m, int x, int y);

void			ft_new_img(t_all *mains, int i, int tmp);

void			ana(char *str, int *err);
int				aaa(char **aaa);
void			j(char **a, char *b, int *e);
void			ft_trimmer(char **map);
char			*ft_add_n(int m, char c, char *s, t_all *mains);
int				reversestrncmp(char *a, char *b, int n);
int				ft_close(int keycode, t_all *mains);
int				ft_height(t_all *mains);
void			ft_rdir(t_all *mains);
void			ft_trashfunc(int i, int **err);

char			*header(t_all *mains, int *weight);
void			bmpcreator(t_all *mains);

void			errors(int *err, t_all *mains);
int				errmessege(int err);
int				seconderrmessege(int err, int i);

void			param_r_w(char *tmp, t_mpp *p, int **err, int *r);
void			param_r_h(char *tmp, t_mpp *p, int **err, int hi);
void			param_txr(char *line, char **dst, int **err, int c);
void			param_fc(char *tmp, int *floor, int **err, int i);
void			filltxradr(t_all *g, int a, int b, int c);
void			drawler(t_all *mains);
void			hv(t_all *mains, float a, float b, float e);
void			hh(t_all *mains, float a, float b, float e);
void			col(t_all *mains, int start, int height, int steps);
void			ft_sprite(t_all *mains, int i, float a);

unsigned int	pixel_txr(t_all *mains, int s, int h);
unsigned int	pixel_txr(t_all *mains, int s, int h);
unsigned int	pixel_txr_two(t_all *mains, int s, int h);
void			sorts(t_all *mains, int i);
int				spritep(t_all *mains, int i, float a);
void			popupsprite(t_all *mains, int place, float spr_d, float size);

#endif
