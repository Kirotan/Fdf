/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:42:40 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/03 21:10:49 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	median_y(t_stray *array)
{
	int		i;
	double	median;

	i = 0;
	median = 0;
	while (i < array[0].len_total)
	{
		median += array[i].y;
		i++;
	}
	median = median / array[0].len_total;
	return (median);
}

static double	median_x(t_stray *array)
{
	int		i;
	double	median;

	i = 0;
	median = 0;
	while (i < array[0].len_total)
	{
		median += array[i].x;
		i++;
	}
	median = median / array[0].len_total;
	return (median);
}

void	re_calcul_center(t_stray *array)
{
	int		i;
	double	med_x;
	double	med_y;

	i = 0;
	med_x = median_x(array);
	med_y = median_y(array);
	while (i < array[0].len_total)
	{
		array[i].x = (array[i].x - med_x) + (WIDTH / 2);
		array[i].y = (array[i].y - med_y) + (HEIGHT / 2);
		i++;
	}
}
