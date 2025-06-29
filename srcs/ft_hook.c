/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:50:03 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/06 16:38:14 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		img = img;
		mlx_put_pixel(img, x, y, 0x0);
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
}

void	handle_rotation(t_hook_pos *data)
{
	clear(data->img);
	rotation_x(data->array, data->angle_x);
	rotation_y(data->array, data->angle_y);
	rotation_z(data->array, data->angle_z);
	drawing_map(data->array, data->img);
}

void	handle_angle(t_hook_pos *data, int key)
{
	if (key == 1)
		data->angle_x += 4;
	if (key == 2)
		data->angle_x -= 4;
	if (key == 3)
		data->angle_y += 4;
	if (key == 4)
		data->angle_y -= 4;
	if (key == 5)
		data->angle_z += 4;
	if (key == 6)
		data->angle_z -= 4;
	if (key == 7)
		data->array->ratio += 0.1;
	if (key == 8 && data->array->ratio > 0.1)
		data->array->ratio -= 0.1;
	handle_rotation(data);
}

void	ft_rotate(t_hook_pos *hook, mlx_t *mlx)
{
	hook->angle_x = 0;
	hook->angle_y = 0;
	hook->angle_z = 0;
	if (mlx_is_key_down(hook->mlx, MLX_KEY_W))
		handle_angle(hook, 1);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_S))
		handle_angle(hook, 2);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_A))
		handle_angle(hook, 3);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_D))
		handle_angle(hook, 4);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_Q))
		handle_angle(hook, 5);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_E))
		handle_angle(hook, 6);
	else if (mlx_is_key_down(mlx, MLX_KEY_2))
		handle_angle(hook, 7);
	else if (mlx_is_key_down(mlx, MLX_KEY_1))
		handle_angle(hook, 8);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	handle_rotation(hook);
}

void	ft_hook(void *param)
{
	mlx_t		*mlx;
	t_hook_pos	*hook;

	hook = param;
	mlx = hook->mlx;
	hook->array[0].ratio = 1;
	ft_rotate(hook, mlx);
}
