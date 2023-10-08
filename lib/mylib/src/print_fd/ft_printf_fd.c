/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:24:07 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/22 14:01:49 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	larg;
	size_t	i;
	int		size;

	i = 0;
	size = 0;
	if (write(fd, 0, 0) != 0 || !format)
		return (-1);
	va_start(larg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			size += ft_print_fd_all(format[i + 1], larg, fd);
		}
		else
			size += ft_print_fd_char(format[i], fd);
		if (format[i + 1] && format[i] == '%')
			i ++;
		i++;
	}
	va_end(larg);
	return (size);
}
