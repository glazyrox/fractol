/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:32:29 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/08 17:48:14 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "mlx.h"
#include "libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define W 1000
#define H 1000
#define max_itaretion 80

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
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    t_min min;
    t_max max;
    t_factor factor;
    t_c c;
    int max_iter;
}              t_glob;

int ft_exit(int flag);
void close_window(int key);

#endif