/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fd_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/22 14:13:19 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_fd_base(unsigned long un, unsigned long size_set, \
char *set, int fd)
{
	int	count;

	count = 0;
	if (un > size_set - 1)
		count += ft_print_fd_base(un / size_set, size_set, set, fd);
	count += ft_print_fd_char(set[un % size_set], fd);
	return (count);
}
