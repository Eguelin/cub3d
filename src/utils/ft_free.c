/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:46:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/10 23:28:05 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_free_cube(t_cube *cube)
{
	if (cube->NO_texture)
		free(cube->NO_texture);
	if (cube->SO_texture)
		free(cube->SO_texture);
	if (cube->WE_texture)
		free(cube->WE_texture);
	if (cube->EA_texture)
		free(cube->EA_texture);
	if (cube->F_colors)
		free(cube->F_colors);
	if (cube->F_colors)
		free(cube->F_colors);
}
void	ft_free_exit(t_cube *cube, int error)
{
	ft_free_cube(cube);
	exit(error);
}
