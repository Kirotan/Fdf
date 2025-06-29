/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_args_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:46:25 by gdoumer           #+#    #+#             */
/*   Updated: 2025/06/29 16:19:12 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_write_args_c(va_list args)
{
	char	tmp;

	tmp = (char)va_arg(args, int);
	if (ft_putchar_fd(tmp, 1) == -1)
		return (-1);
	return (1);
}
