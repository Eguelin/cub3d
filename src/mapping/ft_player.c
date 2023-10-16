/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:54:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/16 21:54:26 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_direction(t_cube *cub, int keycode)
{
	printf("x_start : %f\n", cub->player.x_start);
	printf("y_start : %f\n", cub->player.y_start);
	if (keycode == 122)
	{
		cub->player.y_start -= (cos(cub->player.angle) / 4);
		cub->player.x_start += (sin(cub->player.angle) / 4);
	}
	else if (keycode == 115)
	{
		cub->player.y_start += (cos(cub->player.angle) / 4);
		cub->player.x_start -= (sin(cub->player.angle) / 4);
	}
	else if (keycode == 113)
	{
		cub->player.y_start += (sin(cub->player.angle) / 4);
		cub->player.x_start -= (cos(cub->player.angle) / 4);
	}
	else if (keycode == 100)
	{
		cub->player.y_start -= (sin(cub->player.angle) / 4);
		cub->player.x_start += (cos(cub->player.angle) / 4);
	}
}

void	ft_angle_direction(t_cube *cub, int keycode)
{
	if (keycode == 65361)
		cub->player.angle -= 0.1;
	else if (keycode == 65363)
		cub->player.angle += 0.1;
}
