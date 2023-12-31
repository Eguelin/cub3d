/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:36:37 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/25 18:14:40 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_perror(char const *s, int error)
{
	write(STDERR_FILENO, "Error\n", 7);
	if (error == WRONG_FORMAT)
		write(STDERR_FILENO, "too many arguments\n", 20);
	else if (error == WRONG_FORMAT_BIS)
		write(STDERR_FILENO, "not enough arguments\n", 22);
	else if (error == WRONG_ARGUMENTS)
		ft_printf_fd(STDERR_FILENO, "%s: bad extension, "\
		"cub3d only takes file.cub\n", s);
	else if (error == OPEN_ERROR)
		ft_printf_fd(STDERR_FILENO, "%s: do not open\n", s);
	else if (error == MAP_ERROR)
		write(STDERR_FILENO, "invalid map\n", 13);
	else if (error == MALLOC_ERROR)
		write(STDERR_FILENO, "allocation failure\n", 20);
	else if (error == ENV_ERROR)
		write(STDERR_FILENO, "env is missing\n", 16);
	else if (error == SORT_ERROR)
		ft_printf_fd(STDERR_FILENO, "error with texture/colors path : %s\n", s);
	else if (error == COLORS_ERROR)
		ft_printf_fd(STDERR_FILENO, "error with colors : %s\n", s);
	else if (error == IMG_ERROR)
		write(STDERR_FILENO, "an error occurred during image creation\n", 41);
	if (error == WRONG_FORMAT || error == WRONG_FORMAT_BIS)
		write(STDERR_FILENO, "format: ./cub3d ./path_to_the_map.cub\n", 39);
	return (1);
}
