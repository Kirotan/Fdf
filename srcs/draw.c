/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:41:53 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/06 13:29:14 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx_ptr, x, y, color);
}

void	drawing_map(t_stray *array, mlx_image_t *img)
{
	int		i;

	i = 0;
	while (array[0].len_total > i)
	{
		array[i].x *= (array[0].ratio);
		array[i].y *= (array[0].ratio);
		i++;
	}
	i = 0;
	re_calcul_center(array);
	while (array[0].len_total - 1 > i)
	{
		if ((i + 1) % array[0].len_line != 0)
			draw(array[i], array[i + 1], img);
		if (array[0].len_total - array[0].len_line > i)
			draw(array[i], array[i + array[0].len_line], img);
		i++;
	}
}
