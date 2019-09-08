/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:48:51 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/08 21:29:02 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int other_keys(int key, t_glob *fractal)
{
	if (key == 6)
	{
		printf("%d\n", fractal->max_iter);
		mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->max_iter -= 10;
		mandelbrot(fractal);
	}
	if (key == 7)
	{
		printf("%d\n", fractal->max_iter);
		mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->max_iter += 10;
		mandelbrot(fractal);
	}
	if (key == 8)
	{
		printf("%d\n", fractal->per_bits);
		mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->per_bits += 2;
		mandelbrot(fractal);
	}
	if (key == 9)
	{
		printf("%d\n", fractal->per_bits);
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