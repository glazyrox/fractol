/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:48:51 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/10 23:41:26 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_keys(int key, int x, int y, t_glob *fr)
{
	double re;
	double im;

	im = ((fr->max.im - fr->min.im) * 0.1);
	re = ((fr->max.re - fr->min.re) * 0.1);
	if (key == 4)
	{
		fr->min.im -= im * (1 - (double)y / HT);
		fr->max.im += im * ((double)y / HT);
		fr->min.re -= im * (1 - (double)x/ WT);
		fr->max.re += im * ((double)x / WT);
		mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
		mandelbrot(fr);
	}
	if (key == 5)
	{
		fr->min.im += im * (1 - (double)y / HT);
		fr->max.im -= im * ((double)y / HT);
		fr->min.re += im * (1 - (double)x/ WT);
		fr->max.re -= im * ((double)x / WT);
		mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
		mandelbrot(fr);
	}
	return (0);
}

int other_keys(int key, t_glob *fractal)
{
	if (key == 6)
	{
		printf("not so deep %d\n", fractal->max_iter);
		mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->max_iter -= 10;
		mandelbrot(fractal);
	}
	if (key == 7)
	{
		printf("so deep, baby %d\n", fractal->max_iter);
		mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->max_iter += 10;
		mandelbrot(fractal);
	}
	if (key == 8)
	{
		printf("color: %d\n", fractal->per_bits);
		mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->per_bits += 2;
		mandelbrot(fractal);
	}
	if (key == 9)
	{
		printf("color: %d\n", fractal->per_bits);
		mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->per_bits -= 2;
		mandelbrot(fractal);
	}
	return (0);
}

void close_window(int key)
{
	if (key == 53)
		exit(0);
}