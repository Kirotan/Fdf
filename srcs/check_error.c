/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:34:55 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/05 14:07:44 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_gnl(char *str)
{
	if (!str)
	{
		perror("Empty file.\n");
		exit (EXIT_FAILURE);
	}
}

int	check_fd(char *fdname)
{
	int	fd;

	fd = open(fdname, O_RDONLY);
	if (fd == -1)
	{
		perror("File descriptor error.\n");
		exit (EXIT_FAILURE);
	}
	else if (fd == 0)
	{
		perror("File descriptor empty.\n");
		exit (EXIT_FAILURE);
	}
	return (fd);
}

void	check_argc(int argc)
{
	if (argc < 2)
	{
		perror("Add map please.");
		exit (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		perror("Too many arguments.");
		exit (EXIT_FAILURE);
	}
}
