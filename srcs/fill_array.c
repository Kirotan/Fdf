/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:43:00 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/06 20:00:32 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_points(char **points, t_stray *array)
{
	while (points[array[0].i])
	{
		free(points[array[0].i]);
		(array[0].i)++;
	}
	free(points);
}

static void	core_put_in_tab(t_stray *array, char **points, char *str)
{
	if (array[0].j < array[0].len_total)
	{
		array[array[0].j].z = ft_atoi(points[array[0].i])
			* array[0].height_of_z;
		array[array[0].j].x = (array[0].i) * array[0].zoom;
		array[array[0].j].y = (array[0].j / array[0].len_line) * array[0].zoom;
		array[array[0].j].color = ft_strlower(get_color(points[array[0].i]));
		if (array[array[0].j].color == NULL)
		{
			if (array[array[0].j].z > 0)
			{
				array[array[0].j].color = ft_strdup("ff00ffff");
				verif_4(array, points);
				verif_3(str, array);
			}
			else
			{
				array[array[0].j].color = ft_strdup("ff3070ff");
				verif_4(array, points);
				verif_3(str, array);
			}
		}
		(array[0].j)++;
	}
}

static int	put_line_in_tab(char *str, t_stray *array)
{
	char	**points;
	int		i;

	points = ft_split(str, ' ');
	if (!points)
		verif_1(str, array);
	array[0].i = 0;
	while (points[array[0].i] != NULL)
	{
		i = 0;
		while (points[array[0].i][i] == '-' || points[array[0].i][i] == '+')
			i++;
		if (ft_isdigit(points[array[0].i][i]) == 0)
		{
			ft_free_points(points, array);
			verif_2(str, array);
		}
		core_put_in_tab(array, points, str);
		free(points[array[0].i]);
		(array[0].i)++;
	}
	free(points[array[0].i]);
	free(points);
	verif_5(array);
	return (0);
}

int	extract_map(char *fdname, t_stray **array)
{
	int			fd;
	char		*str;

	fd = check_fd(fdname);
	str = get_next_line(fd);
	check_gnl(str);
	*array = ft_calloc(((get_nb_row(str, ' '))
				* get_nb_lines(fdname)), sizeof(t_stray));
	if (!*array)
	{
		free(str);
		close(fd);
		exit (EXIT_FAILURE);
	}
	give_value(*array, str, fdname);
	while (str != NULL)
	{
		put_line_in_tab(str, *array);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
