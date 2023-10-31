/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:54:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/31 17:57:39 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_north_south(t_cub3d *cub, int keycode)
{
	if (keycode == XK_w)
	{
		cub->player.position.x += (cos(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, X) == EXIT_FAILURE)
			cub->player.position.x -= (cos(cub->player.angle) * 0.10);
		cub->player.position.y += (sin(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, Y) == EXIT_FAILURE)
			cub->player.position.y -= (sin(cub->player.angle) * 0.10);
	}
	else if (keycode == XK_s)
	{
		cub->player.position.x -= (cos(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, X) == EXIT_FAILURE)
			cub->player.position.x += (cos(cub->player.angle) * 0.10);
		cub->player.position.y -= (sin(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, Y) == EXIT_FAILURE)
			cub->player.position.y += (sin(cub->player.angle) * 0.10);
	}
}

void	ft_move_east_west(t_cub3d *cub, int keycode)
{
	if (keycode == XK_a)
	{
		cub->player.position.x += (sin(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, X) == EXIT_FAILURE)
			cub->player.position.x -= (sin(cub->player.angle) * 0.10);
		cub->player.position.y -= (cos(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, Y) == EXIT_FAILURE)
			cub->player.position.y += (cos(cub->player.angle) * 0.10);
	}
	else if (keycode == XK_d)
	{
		cub->player.position.x -= (sin(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, X) == EXIT_FAILURE)
			cub->player.position.x += (sin(cub->player.angle) * 0.10);
		cub->player.position.y += (cos(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, keycode, Y) == EXIT_FAILURE)
			cub->player.position.y -= (cos(cub->player.angle) * 0.10);
	}
}

void	ft_angle_direction(t_cub3d *cub, int keycode)
{
	if (keycode == 65361)
		cub->player.angle -= 0.1;
	else if (keycode == 65363)
		cub->player.angle += 0.1;
}
