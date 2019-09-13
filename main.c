/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:35:28 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/13 19:21:34 by rgwayne-         ###   ########.fr       */
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

void *ft_name(void *inc)
{
    t_glob *fl;
    fl = (t_glob *)inc;
    if (!(ft_strcmp(fl->name, "mandelbrot")))
    {
        mandelbrot(fl);
    }
    else if (!(ft_strcmp(fl->name, "julia")))
        julia(fl);
    else if (!(ft_strcmp(fl->name, "burningship")))
        burningship(fl);
    return (NULL);
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
    fl->per_bits = 8;
    fl->prb = 1;
    fl->min.re = -2.0;
    fl->max.re = 2.0;
    fl->min.im = -2.0;
    fl->max.im = fl->min.im + (fl->max.re - fl->min.re) * HT / WT;
    fl->max_iter = 100;
    fl->julia.re = 0.7;
    fl->julia.im = 0.27;
    fl->name = name;
    return (fl);
}

int main(int ac, char **av)
{
    t_glob *fractal;

    if (ac < 2 || (ft_strcmp(av[1], "mandelbrot")
    && ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "burningship")))
        ft_exit (1);
    fractal = get_fractal(av[1]);
    ft_launch_fractol(fractal);
    mlx_hook(fractal->win_ptr, 2, 0, (void*)other_keys, fractal);
    mlx_hook(fractal->win_ptr, 4, 0, (void*)mouse_keys, (void*)fractal);
    if (!(ft_strcmp(fractal->name, "julia")))
        mlx_hook(fractal->win_ptr, 6, 0, (void*)mouse_move, fractal);
    mlx_key_hook(fractal->win_ptr, (void*)close_window, fractal);
    mlx_loop(fractal->mlx_ptr);
    free(fractal);
    return (0);
}