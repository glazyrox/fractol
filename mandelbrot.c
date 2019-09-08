/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:46:55 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/08 21:29:01 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_colorize(t_glob *fl, int i)
{
    fl->t = (double)i / fl->max_iter;
    fl->clr.r = (char)(9 * (1 - fl->t) * pow(fl->t, 3) * 255);
    fl->clr.g = (char)(15 * pow((1 - fl->t), 2) * pow(fl->t, 2) * 255);
    fl->clr.b = (char)(8.5 * pow((1 - fl->t), 3) * fl->t * 0);
    fl->clr.color = (fl->clr.g << fl->per_bits) + (fl->clr.b) + (fl->clr.r << fl->per_bits);
    return (fl->clr.color);
}

t_glob *mandelbrot(t_glob *fl)
{
    int x;
    int y;
    int i;
    t_complex min;
    t_complex z;
    
    y = 0;
    while (y++ < HT)
    {
        fl->c.im = fl->max.im - y * fl->factor.im;
        x = 0;
        while (x++ < WT)
        {
            fl->c.re = fl->min.re + x * fl->factor.re;
            z = init_complex(fl->c.re, fl->c.im);
            i = 0;
            while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i++ < fl->max_iter)
                z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fl->c.re,
                2.0 * z.re * z.im + fl->c.im);
            mlx_pixel_put(fl->mlx_ptr, fl->win_ptr, x, y, ft_colorize(fl, i));
        }
    }
    return (fl);
}