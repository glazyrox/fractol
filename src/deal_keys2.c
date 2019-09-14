/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:23:36 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/14 16:27:37 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_arr2(int key, t_glob *fr)
{
	double	re;
	double	im;

	im = fr->max.im - fr->min.im;
	re = fr->max.re - fr->min.re;
	if (key == 126)
	{
		fr->max.im -= im * 0.1;
		fr->min.im -= im * 0.1;
	}
	if (key == 125)
	{
		fr->max.im += im * 0.1;
		fr->min.im += im * 0.1;
	}
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	ft_launch_fractol(fr);
}
