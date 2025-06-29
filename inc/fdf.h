/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:55:30 by gdoumer           #+#    #+#             */
/*   Updated: 2025/06/29 14:57:18 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 3000
# define HEIGHT 2000

# include "MLX42.h"
# include "../libft/include/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_struc_array
{
	double		x;
	double		y;
	double		z;
	int			i;
	int			j;
	char		*color;
	int			len_total;
	int			len_line;
	int			len_raw;
	int			start_x;
	int			start_y;
	double		ratio;
	double		zoom;
	int			height_of_z;
}	t_stray;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		inc_y;
	int		inc_x;
	int		hill;
	int		error;
	int		inc_e;
	int		p;
}	t_bres;

typedef struct s_hook_pos
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_stray		*array;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	int			height_of_z;
}	t_hook_pos;

void			check_argc(int argc);
int				check_fd(char *fdname);
void			check_gnl(char *str);
int				extract_map(char *filename, t_stray **vars);
void			drawing_map(t_stray *array, mlx_image_t	*img);
void			draw(t_stray start, t_stray end, void *img);
void			draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color);
void			ft_rotation(t_stray *array);
void			rotation_x(t_stray *array, int angle);
void			rotation_y(t_stray *array, int angle);
void			rotation_z(t_stray *array, int angle);
void			re_calcul_center(t_stray *array);
char			*get_color(char *str);
void			free_everythings(t_stray *array, t_hook_pos *hook);
void			ft_hook(void *param);
void			create_mlx(mlx_t **mlx, mlx_image_t **img);
unsigned int	get_nb_row(char const *s, char c);
int				get_nb_lines(char *fdname);
void			give_value(t_stray *array, char *str, char *fdname);
void			verif_1(char *str, t_stray *array);
void			verif_2(char *str, t_stray *array);
void			verif_3(char *str, t_stray *array);
void			verif_4(t_stray *array, char **points);
void			verif_5(t_stray *array);

#endif
