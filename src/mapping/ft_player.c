/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:54:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/18 14:33:05 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_direction(t_cub3d *cub, int keycode)
{
	printf("x : %f\n", cub->player.position.x);
	printf("y : %f\n", cub->player.position.y);
	if (keycode == KEY_W)
	{
		cub->player.position.y += (sin(cub->player.angle) * 0.25);
		cub->player.position.x -= (cos(cub->player.angle) * 0.25);
	}
	else if (keycode == KEY_S)
	{
		cub->player.position.y -= (sin(cub->player.angle) * 0.25);
		cub->player.position.x += (cos(cub->player.angle) * 0.25);
	}
	else if (keycode == KEY_A)
	{
		cub->player.position.y -= (cos(cub->player.angle) * 0.25);
		cub->player.position.x += (sin(cub->player.angle) * 0.25);
	}
	else if (keycode == KEY_D)
	{
		cub->player.position.y += (cos(cub->player.angle) * 0.25);
		cub->player.position.x -= (sin(cub->player.angle) * 0.25);
	}
}

void	ft_angle_direction(t_cub3d *cub, int keycode)
{
	if (keycode == 65361)
		cub->player.angle -= 0.1;
	else if (keycode == 65363)
		cub->player.angle += 0.1;
}
