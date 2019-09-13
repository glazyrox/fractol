/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:06:51 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/13 18:02:44 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_launch_fractol(t_glob *fr)
{
	pthread_t	*threads;
	t_glob		*data;
	int			i;
	int			step;

	step = HT / THREAD_NUMBER + WT - HT / THREAD_NUMBER * THREAD_NUMBER;
	threads = (pthread_t *)ft_memalloc(sizeof(pthread_t) * THREAD_NUMBER);
	data = (t_glob *)ft_memalloc(sizeof(t_glob) * THREAD_NUMBER);
	i = -1;
	while (++i < THREAD_NUMBER)
	{
		data[i] = *fr;
		data[i].ymin = step * i;
		data[i].ymax = step * (i + 1);
		pthread_create(&(threads[i]), NULL, ft_name, &(data[i]));
	}
	i = -1;
	while (++i < THREAD_NUMBER)
	{
		pthread_join(threads[i], NULL);
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img.img_ptr, 0, 0);
	free(threads);
	free(data);
}