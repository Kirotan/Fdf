/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:02:56 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/03 21:10:05 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_mlx(mlx_t **mlx, mlx_image_t **img)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	*mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		return ;
	*img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!*img || (mlx_image_to_window(*mlx, *img, 0, 0) < 0))
		return ;
}
