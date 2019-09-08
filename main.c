/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:35:28 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/08 21:29:03 by rgwayne-         ###   ########.fr       */
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
    t_complex min;

    min = init_complex(-2.0, -2.0);
    if (!(fl = malloc(sizeof(t_glob))))
        ft_exit(2);
    fl->mlx_ptr = mlx_init();
    fl->win_ptr = mlx_new_window(fl->mlx_ptr, WT, HT, name);
    fl->per_bits = 16;
    fl->min.re = -2.0;
    fl->max.re = 2.0;
    fl->min.im = -2.0;
    fl->max.im = fl->min.im + (fl->max.re - fl->min.re) * HT / WT;
    fl->zoom = 1;
    fl->max_iter = 100;
    fl->factor.re = (fl->max.re - fl->min.re) / (WT - 1);
    fl->factor.im = (fl->max.im - fl->min.im) / (HT - 1);
    if (!(ft_strcmp(name, "mandelbrot")))
        mandelbrot(fl);
    else if (!(ft_strcmp(name, "julia")))
        ft_exit(3);
    else if (!(ft_strcmp(name, "random")))
        ft_exit(3);
    return (fl);
}

int main(int ac, char **av)
{
    t_glob *fractal;
    if (ac < 2 || (ft_strcmp(av[1], "mandelbrot")
    && ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "random")))
        ft_exit (1);
    fractal = get_fractal(av[1]);
    mlx_hook(fractal->win_ptr, 2, 4, other_keys, fractal);
    mlx_key_hook(fractal->win_ptr, (void*)close_window, fractal);
    mlx_loop(fractal->mlx_ptr);
    return (0);
}