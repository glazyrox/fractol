/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:35:28 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/08 17:48:37 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void		*create_new_image(t_glob *fract)
// {
// 	void	*img_ptr;

// 	img_ptr = mlx_new_image(fract->mlx_ptr, W, H);
// 	return (img_ptr);
// }

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
    int y;
    int x;
    t_complex min;
    t_complex z;
    int i;
    double t;
    int red;
    int green;
    int blue;
    long int color = 0;

    y = 0;
    min = init_complex(-2.0, -2.0);
    if (!(fl = malloc(sizeof(t_glob))))
        ft_exit(2);
    fl->mlx_ptr = mlx_init();
    fl->win_ptr = mlx_new_window(fl->mlx_ptr, W, H, name);
    //fl->img_ptr = create_new_image(fl);
    fl->min.re = -2.0;
    fl->max.re = 2.0;
    fl->min.im = -2.0;
    fl->max.im = fl->min.im + (fl->max.re - fl->min.re) * H / W;
    fl->factor.re = (fl->max.re - fl->min.re) / (W - 1);
    fl->factor.im = (fl->max.im - fl->min.im) / (H - 1);
    fl->max_iter = 50;
    while (y < H)
    {
        fl->c.im = fl->max.im - y * fl->factor.im;
        x = 0;
        while (x < W)
        {
            fl->c.re = fl->min.re + x * fl->factor.re;
            z = init_complex(fl->c.re, fl->c.im);
            i = 0;
            while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < max_itaretion)
            {
                z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fl->c.re,
                2.0 * z.re * z.im + fl->c.im);
                i++;
            }
            t = (double)i / (double)max_itaretion;
            red = (char)(9 * (1 - t) * pow(t, 3) * 130);
            green = (char)(15 * pow((1 - t), 2) * pow(t, 2) * 100);
            blue = (char)(8.5 * pow((1 - t), 3) * t * 0);
            color = (green << 8) + (blue) + (red << 16);
            mlx_pixel_put(fl->mlx_ptr, fl->win_ptr, x, y, color);
            x++;
        }
        y++;
    }
    
    return (fl);
}

int main(int ac, char **av)
{
    t_glob *fractal;
    if (ac < 2 || (ft_strcmp(av[1], "mandelbrot")
    && ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "random")))
        ft_exit (1);
    fractal = get_fractal(av[1]);
    mlx_key_hook(fractal->win_ptr, (void*)close_window, (void*)fractal);
    mlx_loop(fractal->mlx_ptr);
    return (0);
}