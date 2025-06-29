/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:13:46 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/06 21:18:31 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_nb_row(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

int	get_nb_lines(char *fdname)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = check_fd(fdname);
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	give_value(t_stray *array, char *str, char *fdname)
{
	double	widt;
	double	heigh;

	array[0].len_line = get_nb_row(str, ' ');
	array[0].len_raw = get_nb_lines(fdname);
	array[0].len_total = array[0].len_line * array[0].len_raw;
	array[0].height_of_z = 5;
	widt = HEIGHT / array[0].len_line;
	heigh = WIDTH / array[0].len_raw;
	if (widt < heigh)
		array[0].zoom = widt;
	else
		array[0].zoom = heigh;
	array[0].i = 0;
	array[0].j = 0;
}
