/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:22:47 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/22 13:49:11 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_fd_str(const char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_print_fd_char(s[i], fd);
		i++;
	}
	return (i);
}
