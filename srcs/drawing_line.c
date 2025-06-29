/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:51:59 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/05 14:28:59 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_x_zero(t_stray start, t_stray end, void *img, t_bres bres)
{
	bres.p = 0;
	while ((int)start.y != (int)end.y + bres.inc_y)
	{
		draw_pixel(img, start.x, start.y, ft_atoi_base(start.color));
		start.y += bres.inc_y;
	}
}

static void	draw_y_zero(t_stray start, t_stray end, void *img, t_bres bres)
{
	bres.p = 0;
	while ((int)start.x != (int)end.x + bres.inc_x)
	{
		draw_pixel(img, start.x, start.y, ft_atoi_base(start.color));
		start.x += bres.inc_x;
		bres.p++;
	}
}

static void	draw_bigger(t_stray start, t_stray end, void *img, t_bres bres)
{
	bres.p = 0;
	bres.hill = bres.dy << 1;
	bres.error = -(bres.dx);
	bres.inc_e = bres.error << 1;
	while ((int)start.x != (int)end.x + bres.inc_x)
	{
		draw_pixel(img, start.x, start.y, ft_atoi_base(start.color));
		bres.error += bres.hill;
		if (bres.error >= 0)
		{
			start.y += bres.inc_y;
			bres.error += bres.inc_e;
		}
		start.x += bres.inc_x;
		bres.p++;
	}
}

static void	draw_other(t_stray start, t_stray end, void *img, t_bres bres)
{
	bres.p = 0;
	bres.hill = bres.dx << 1;
	bres.error = -(bres.dy);
	bres.inc_e = bres.error << 1;
	while ((int)start.y != (int)end.y + bres.inc_y)
	{
		draw_pixel(img, start.x, start.y, ft_atoi_base(start.color));
		bres.error += bres.hill;
		if (bres.error >= 0)
		{
			start.x += bres.inc_x;
			bres.error += bres.inc_e;
		}
		start.y += bres.inc_y;
		bres.p++;
	}
}

void	draw(t_stray start, t_stray end, void *img)
{
	t_bres	bres;

	bres.dy = end.y - start.y;
	bres.dx = end.x - start.x;
	bres.inc_y = 1;
	bres.inc_x = 1;
	if (bres.dy < 0)
	{
		bres.inc_y = -1;
		bres.dy *= -1;
	}
	if (bres.dx < 0)
	{
		bres.inc_x = -1;
		bres.dx *= -1;
	}
	if (bres.dy == 0)
		draw_y_zero(start, end, img, bres);
	else if (bres.dx == 0)
		draw_x_zero(start, end, img, bres);
	else if (bres.dx >= bres.dy)
		draw_bigger(start, end, img, bres);
	else
		draw_other(start, end, img, bres);
}
