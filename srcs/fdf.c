/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:50:55 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/06 20:02:57 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_stray		*array;
	t_hook_pos	*hook;

	check_argc(argc);
	extract_map(argv[1], &array);
	hook = malloc(sizeof(t_hook_pos));
	if (!hook)
		return (0);
	create_mlx(&mlx, &img);
	hook->mlx = mlx;
	hook->img = img;
	hook->array = array;
	mlx_loop_hook(mlx, &ft_hook, hook);
	mlx_loop(mlx);
	free_everythings(array, hook);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
