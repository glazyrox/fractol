/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:39:11 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/14 16:09:39 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_glob *fl)
{
	int				i;
	t_complex		z;
	double			step_i;
	double			step_r;

	step_i = ((fl->max.im - fl->min.im) / HT);
	step_r = ((fl->max.re - fl->min.re) / WT);
	fl->y = 0;
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
				z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fl->julia.re,
						2.0 * z.re * z.im + fl->julia.im);
			put_pixel_to_img(fl->x, fl->y, fl, ft_colorize(fl, i));
		}
	}
}
