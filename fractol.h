/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:32:29 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/12 19:05:06 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "mlx.h"
#include "libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define WT 700
#define HT 700

typedef struct s_image
{
    void *img_ptr;
    int *data;
    int line_size;
    int bits_per_pixel;
    int end;
}              t_image;

typedef struct  s_color
{
    int r;
    int g;
    int b;
    int color;
}               t_color;


typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_c
{
    double im;
    double re;
}              t_c;

typedef struct  s_factor
{
    double re;
    double im;
}               t_factor;         

typedef struct  s_min
{
    double re;
    double im;
}               t_min;

typedef struct s_max
{
    double re;
    double im;
}               t_max;

typedef struct s_global
{
    int flag;
    double prex;
    double prey;
    int x;
    double x1;
    int y;
    double y1;
    void *mlx_ptr;
    void *win_ptr;
    t_image img;
    int max_iter;
    double t;
    int per_bits;
    t_complex	move;
    t_min min;
    t_max max;
    t_factor factor;
    t_color clr;
    t_c c;
    t_complex julia;
    int fract;
}              t_glob;

int ft_colorize(t_glob *fl, int i);
void    put_pixel_to_img(int x, int y, t_glob *fl, int color);
int ft_exit(int flag);
void close_window(int key);
int mandelbrot(t_glob *fr);
t_complex init_complex(double re, double im);
int other_keys(int key, t_glob *fractal);
int mouse_keys(int key, int x, int y, t_glob *fractal);
int burningship(t_glob *fl);
int julia(t_glob *fl);
void mouse_move(int x, int y, t_glob *fr);

#endif