/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:38:59 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/22 13:48:51 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static int	ft_print_fd_all_2(char c, va_list arg, int fd);

int	ft_print_fd_all(char c, va_list arg, int fd)
{
	int		size;
	char	*s;

	size = 0;
	if (c == 'c')
		size = ft_print_fd_char(va_arg(arg, int), fd);
	else if (c == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
			size = ft_print_fd_str("(null)", fd);
		else
			size = ft_print_fd_str(s, fd);
	}
	else if (c == 'p')
		size = ft_print_fd_address(va_arg(arg, long), fd);
	else if (c == 'd' || c == 'i')
		size = ft_print_fd_nbr(va_arg(arg, int), fd);
	else if (c == 'u')
		size = ft_print_fd_base(va_arg(arg, unsigned int), 10, \
		"0123456789", fd);
	else
		size = ft_print_fd_all_2(c, arg, fd);
	return (size);
}

static int	ft_print_fd_all_2(char c, va_list arg, int fd)
{
	int	size;

	size = 0;
	if (c == 'x')
		size = ft_print_fd_base(va_arg(arg, unsigned int), 16, \
		"0123456789abcdef", fd);
	else if (c == 'X')
		size = ft_print_fd_base(va_arg(arg, unsigned int), 16, \
		"0123456789ABCDEF", fd);
	else if (c == '%')
		size = ft_print_fd_char('%', fd);
	return (size);
}
