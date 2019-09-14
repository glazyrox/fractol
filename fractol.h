/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:32:29 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/14 16:41:28 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"
# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# define WT				700
# define HT 			700
# define THREAD_NUMBER	2

typedef struct	s_image
{
	void		*p;
	int			*dt;
	int			lz;
	int			b;
	int			k;
}				t_image;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			c;
}				t_color;

typedef	struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_c
{
	double		im;
	double		re;
}				t_c;

typedef struct	s_factor
{
	double		re;
	double		im;
}				t_factor;

typedef struct	s_min
{
	double		re;
	double		im;
}				t_min;

typedef struct	s_max
{
	double		re;
	double		im;
}				t_max;

typedef struct	s_global
{
	int			b;
	char		*name;
	int			flag;
	double		prex;
	double		prey;
	int			x;
	double		x1;
	int			y;
	double		y1;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		i;
	int			max_iter;
	double		t;
	int			pb;
	t_complex	move;
	t_min		min;
	t_max		max;
	int			ymin;
	int			ymax;
	t_factor	factor;
	t_color		cl;
	t_c			c;
	t_complex	julia;
	int			fract;
}				t_glob;

int				ft_colorize(t_glob *fl, int i);
void			put_pixel_to_img(int x, int y, t_glob *fl, int color);
int				ft_exit(int flag);
void			close_window(int key);
void			mandelbrot(t_glob *fr);
t_complex		init_complex(double re, double im);
int				other_keys(int key, t_glob *fractal);
int				mouse_keys(int key, int x, int y, t_glob *fractal);
void			burningship(t_glob *fl);
void			julia(t_glob *fl);
void			mouse_move(int x, int y, t_glob *fr);
void			ft_launch_fractol(t_glob *fr);
void			*ft_name(void *inc);
void			move_arr(int key, t_glob *fr);
t_glob			*get_fractal2(char *name);
void			move_arr2(int key, t_glob *fr);

#endif
