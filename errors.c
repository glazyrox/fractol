/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:00:48 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/10 19:36:53 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_exit(int flag)
{
    if (flag == 1)
        ft_putendl("usage: ./fractal [mandelbrot, julia, random] ¯\\_(ツ)_/¯");
    if (flag == 2)
        ft_putendl("troubles with allocate");
    if (flag == 3)
        ft_putendl("Will be soon...");
    exit (0);
}