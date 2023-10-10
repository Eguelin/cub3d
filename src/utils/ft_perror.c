/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:36:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/10 18:26:05 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_perror(const char *s, int error)
{
	write(STDERR_FILENO, "cub3d: ", 7);
	if (error == WRONG_FORMAT)
		ft_printf_fd(STDERR_FILENO, "%s\n./cub3d ./path_to_the_map.cub", s);
	else if (error == WRONG_ARGUMENTS)
		ft_printf_fd(STDERR_FILENO, "%s: bad extension, cub3d only takes .cub", s);
	else if (error == OPEN_ERROR)
		ft_printf_fd(STDERR_FILENO, "%s: do not open", s);
	else if (error == MALLOC_ERROR)
		write(STDERR_FILENO, "allocation failure\n", 19);
	return (1);
}
