/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:35:28 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/12 19:04:40 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex init_complex(double re, double im)
{
    t_complex complex;

    complex.re = re;
    complex.im = im;
    return (complex);
}

t_glob *get_fractal(char *name)
{
    t_glob *fl;

    if (!(fl = malloc(sizeof(t_glob))))
        ft_exit(2);
    fl->flag = 0;
    fl->mlx_ptr = mlx_init();
    fl->win_ptr = mlx_new_window(fl->mlx_ptr, WT, HT, name);
    fl->img.img_ptr = mlx_new_image(fl->mlx_ptr, WT, HT);
    fl->img.data = (int *)mlx_get_data_addr(fl->img.img_ptr, &fl->img.bits_per_pixel, &fl->img.line_size, &fl->img.end);
    fl->per_bits = 2;
    fl->min.re = -2.0;
    fl->max.re = 2.0;
    fl->min.im = -2.0;
    fl->max.im = fl->min.im + (fl->max.re - fl->min.re) * HT / WT;
    fl->max_iter = 100;
    fl->julia.re = 0.7;
    fl->julia.im = 0.27;
    if (!(ft_strcmp(name, "mandelbrot")))
        fl->fract = mandelbrot(fl);
    else if (!(ft_strcmp(name, "julia")))
        fl->fract = julia(fl);
    else if (!(ft_strcmp(name, "burningship")))
        fl->fract = burningship(fl);
    return (fl);
}

int main(int ac, char **av)
{
    t_glob *fractal;
    if (ac < 2 || (ft_strcmp(av[1], "mandelbrot")
    && ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "burningship")))
        ft_exit (1);
    fractal = get_fractal(av[1]);
    mlx_hook(fractal->win_ptr, 2, 0, &other_keys, fractal);
    mlx_hook(fractal->win_ptr, 4, 0, (void*)mouse_keys, (void*)fractal);
    if (fractal->flag == 2)
        mlx_hook(fractal->win_ptr, 6, 0, (void*)mouse_move, fractal);
    mlx_key_hook(fractal->win_ptr, (void*)close_window, fractal);
    mlx_loop(fractal->mlx_ptr);
    return (0);
}