/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:36:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/12 16:07:08 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_perror(const char *s, int error)
{
	write(STDERR_FILENO, "Error\n", 7);
	if (error == WRONG_FORMAT)
		write(STDERR_FILENO, "too many arguments\n", 19);
	else if (error == WRONG_FORMAT_BIS)
		write(STDERR_FILENO, "not enough arguments\n", 21);
	else if (error == WRONG_ARGUMENTS)
		ft_printf_fd(STDERR_FILENO, "%s: bad extension, "\
		"cub3d only takes file.cub\n", s);
	else if (error == OPEN_ERROR)
		ft_printf_fd(STDERR_FILENO, "%s: do not open\n", s);
	else if (error == MALLOC_ERROR)
		write(STDERR_FILENO, "allocation failure\n", 20);
	else if (error == ENV_ERROR)
		write(STDERR_FILENO, "env is missing\n", 15);
	else if (error == SORT_ERROR)
		write(STDERR_FILENO, "error occurred with texture/color paths\n", 41);
	else if (error == COLORS_ERROR)
		ft_printf_fd(STDERR_FILENO, "wrong %s colors\n", s);
	if (error == WRONG_FORMAT || error == WRONG_FORMAT_BIS)
		write(STDERR_FILENO, "format: ./cub3d ./path_to_the_map.cub\n", 38);
	return (1);
}
