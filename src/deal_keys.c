/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:48:51 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/14 16:24:59 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_keys(int key, int x, int y, t_glob *fr)
{
	double	re;
	double	im;

	im = ((fr->max.im - fr->min.im) * 0.1);
	re = ((fr->max.re - fr->min.re) * 0.1);
	if (key == 4)
	{
		fr->min.im += im * (1 - (double)y / HT);
		fr->max.im -= im * ((double)y / HT);
		fr->min.re += im * ((double)x / WT);
		fr->max.re -= im * (1 - (double)x / WT);
	}
	if (key == 5)
	{
		fr->min.im -= im * (1 - (double)y / HT);
		fr->max.im += im * ((double)y / HT);
		fr->min.re -= im * ((double)x / WT);
		fr->max.re += im * (1 - (double)x / WT);
	}
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	ft_launch_fractol(fr);
	return (0);
}

void	mouse_move(int x, int y, t_glob *fr)
{
	fr->julia = init_complex(
			4 * ((double)x / WT - 0.5),
			4 * ((double)(HT - y) / HT - 0.5));
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	ft_launch_fractol(fr);
}

int		other_keys(int key, t_glob *fractal)
{
	if (key == 6)
	{
		fractal->max_iter -= 10;
	}
	if (key == 7)
	{
		fractal->max_iter += 10;
	}
	if (key == 8)
	{
		fractal->b += 2;
		fractal->pb += 1;
	}
	if (key == 9)
	{
		fractal->b -= 2;
		fractal->pb -= 1;
	}
	else if (key == 124 || key == 123 || key == 125 || key == 126)
		move_arr(key, fractal);
	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	ft_launch_fractol(fractal);
	return (0);
}

void	move_arr(int key, t_glob *fr)
{
	double	re;
	double	im;

	im = fr->max.im - fr->min.im;
	re = fr->max.re - fr->min.re;
	if (key == 124)
	{
		fr->max.re -= re * 0.1;
		fr->min.re -= re * 0.1;
	}
	if (key == 123)
	{
		fr->max.re += re * 0.1;
		fr->min.re += re * 0.1;
	}
	if (key == 126 || key == 125)
		move_arr2(key, fr);
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	ft_launch_fractol(fr);
}

void	close_window(int key)
{
	if (key == 53)
		exit(0);
}
