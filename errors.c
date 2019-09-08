/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:00:48 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/08 15:51:10 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_exit(int flag)
{
    if (flag == 1)
        ft_putendl("usage: ./fractal [mandelbrot, julia, random] ¯\\_(ツ)_/¯");
    if (flag == 2)
        ft_putendl("troubles with malloc ¯\\_(ツ)_/¯");
    exit (0);
}