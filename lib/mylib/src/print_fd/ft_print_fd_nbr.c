/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/22 13:49:08 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_fd_nbr(int n, int fd)
{
	unsigned int	un;
	int				count;

	un = n;
	count = 0;
	if (n < 0)
	{
		count += ft_print_fd_char('-', fd);
		un *= -1;
	}
	if (un > 9)
		count += ft_print_fd_nbr(un / 10, fd);
	count += ft_print_fd_char((un % 10) + '0', fd);
	return (count);
}
