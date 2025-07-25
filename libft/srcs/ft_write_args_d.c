/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_args_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:23:05 by gdoumer           #+#    #+#             */
/*   Updated: 2025/06/29 16:19:12 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_write_args_d(va_list args)
{
	char	*nb;
	int		len;

	nb = ft_itoa(va_arg(args, int));
	len = ft_strlen(nb);
	ft_putstr_fd(nb, 1);
	if (!nb)
		return (-1);
	free(nb);
	return (len);
}
