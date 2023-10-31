/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:54:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/31 15:59:05 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_north_south(t_cub3d *cub, int keycode)
{
	if (keycode == XK_W)
	{
		cub->player.position.x -= (cos(cub->player.angle) * 0.20);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, X) == EXIT_FAILURE)
			cub->player.position.x += (cos(cub->player.angle) * 0.20);
		cub->player.position.y += (sin(cub->player.angle) * 0.20);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, Y) == EXIT_FAILURE)
			cub->player.position.y -= (sin(cub->player.angle) * 0.20);
	}
	else if (keycode == XK_S)
	{
		cub->player.position.x += (cos(cub->player.angle) * 0.20);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, X) == EXIT_FAILURE)
			cub->player.position.x -= (cos(cub->player.angle) * 0.20);
		cub->player.position.y -= (sin(cub->player.angle) * 0.20);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, Y) == EXIT_FAILURE)
			cub->player.position.y += (sin(cub->player.angle) * 0.20);
	}
}

void	ft_move_east_west(t_cub3d *cub, int keycode)
{
	if (keycode == XK_A)
	{
		cub->player.position.x += (sin(cub->player.angle) * 0.20);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, X) == EXIT_FAILURE)
			cub->player.position.x -= (sin(cub->player.angle) * 0.20);
		cub->player.position.y -= (cos(cub->player.angle) * 0.20);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, Y) == EXIT_FAILURE)
			cub->player.position.y += (cos(cub->player.angle) * 0.20);
	}
	else if (keycode == XK_D)
	{
		cub->player.position.x -= (sin(cub->player.angle) * 0.20);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, X) == EXIT_FAILURE)
			cub->player.position.x += (sin(cub->player.angle) * 0.20);
		cub->player.position.y += (cos(cub->player.angle) * 0.20);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, Y) == EXIT_FAILURE)
			cub->player.position.y -= (cos(cub->player.angle) * 0.20);
	}
}

void	ft_angle_direction(t_cub3d *cub, int keycode)
{
	if (keycode == 65361)
		cub->player.angle -= 0.1;
	else if (keycode == 65363)
		cub->player.angle += 0.1;
}