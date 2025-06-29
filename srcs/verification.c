/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:41:05 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/06 19:24:24 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	verif_1(char *str, t_stray *array)
{
	free(str);
	while (array[0].i < array[0].j)
	{
		free(array[array[0].i].color);
		(array[0].i)++;
	}
	free(array);
	perror("Malloc error.\n");
	exit (EXIT_FAILURE);
}

void	verif_2(char *str, t_stray *array)
{
	array[0].i = 0;
	free(str);
	while (array[0].i < array[0].j)
	{
		free(array[array[0].i].color);
		(array[0].i)++;
	}
	free(array);
	perror("Bad digit.\n");
	exit (EXIT_FAILURE);
}

void	verif_3(char *str, t_stray *array)
{
	if (!array[array[0].j].color)
	{
		array[0].i = 0;
		free(str);
		while (array[0].i < array[0].j)
		{
			free(array[array[0].i].color);
			(array[0].i)++;
		}
		free(array);
		perror("Malloc error, transparent line.\n");
		exit (EXIT_FAILURE);
	}
}

void	verif_4(t_stray *array, char **points)
{
	if (!array[array[0].j].color)
	{
		while (points[array[0].i])
		{
			free(points[array[0].i]);
			(array[0].i)++;
		}
		free(points);
	}
}

void	verif_5(t_stray *array)
{
	if (array[0].i != array[0].len_line)
	{
		array[0].i = 0;
		while (array[0].i < array[0].j)
		{
			free(array[array[0].i].color);
			(array[0].i)++;
		}
		free(array);
		perror("Bad line.\n");
		exit (EXIT_FAILURE);
	}
}
