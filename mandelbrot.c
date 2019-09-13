/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:46:55 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/13 17:30:55 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    put_pixel_to_img(int x, int y, t_glob *fl, int color)
{
    if (x >= 0 && x < WT && y >= 0 && y < HT)
        fl->img.data[x + y * WT] = color;
}

int ft_colorize(t_glob *fl, int i)
{
    fl->t = (double)i / fl->max_iter;
    fl->clr.r = (char)(9 * (1 - fl->t) * pow(fl->t, 3) * 221);
    fl->clr.g = (char)(15 * pow((1 - fl->t), 2) * pow(fl->t, 2) * 160);
    fl->clr.b = (char)(8.5 * pow((1 - fl->t), 3) * fl->t * 0);
    fl->clr.color = (fl->clr.r << fl->prb) + (fl->clr.g << fl->per_bits) + (fl->clr.b << fl->prb);
    return (fl->clr.color);
}

void mandelbrot(t_glob *fl)
{
    int i;
    t_complex z;
    double step_i;
    double step_r;
    
    step_i = ((fl->max.im - fl->min.im) / HT);
    step_r = ((fl->max.re - fl->min.re) / WT);
    fl->y = fl->ymin;
    while (fl->y++ < fl->ymax)
    {
        fl->x = 0;
        while (fl->x++ < WT)
        {
            fl->c.im = fl->max.im - step_i * fl->y;
            fl->c.re = fl->min.re + step_r * fl->x;
            z = init_complex(fl->c.re, fl->c.im);
            i = 0;
            while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i++ < fl->max_iter)
                z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fl->c.re,
                2.0 * z.re * z.im + fl->c.im);
            put_pixel_to_img(fl->x, fl->y, fl, ft_colorize(fl, i));
        }
    }
}