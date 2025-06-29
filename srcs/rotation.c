/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:49:32 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/05 18:09:48 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_stray *array, int angle)
{
	int		i;
	double	y;
	double	z;
	double	radian;

	if (angle != 0)
	{
		i = 0;
		radian = angle * (M_PI / 180.00);
		while (i < array->len_total)
		{
			y = array[i].y;
			z = array[i].z;
			array[i].y = (y * cos(radian)) - (z * sin(radian));
			array[i].z = (y * sin(radian)) + (z * cos(radian));
			i++;
		}
	}
}

void	rotation_y(t_stray *array, int angle)
{
	int		i;
	double	x;
	double	z;
	double	radian;

	if (angle != 0)
	{
		i = 0;
		radian = angle * (M_PI / 180);
		while (i < array->len_total)
		{
			x = array[i].x;
			z = array[i].z;
			array[i].x = (x * cos(radian)) + (z * sin(radian));
			array[i].z = (-x * sin(radian)) + (z * cos(radian));
			i++;
		}
	}
}

void	rotation_z(t_stray *array, int angle)
{
	int		i;
	double	x;
	double	y;
	double	radian;

	if (angle != 0)
	{
		i = 0;
		radian = angle * (M_PI / 180);
		while (i < array->len_total)
		{
			x = array[i].x;
			y = array[i].y;
			array[i].x = (x * cos(radian)) - (y * sin(radian));
			array[i].y = (x * sin(radian)) + (y * cos(radian));
			i++;
		}
	}
}
