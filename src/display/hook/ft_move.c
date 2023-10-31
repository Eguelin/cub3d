/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:54:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/01 00:32:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_move_north_south(t_cub3d *cub);
static void	ft_move_east_west(t_cub3d *cub);
static void	ft_angle_direction(t_cub3d *cub);

void	ft_move(t_cub3d *cub)
{
	ft_move_north_south(cub);
	ft_move_east_west(cub);
	ft_angle_direction(cub);
}

static void	ft_move_north_south(t_cub3d *cub)
{
	if (cub->hook[UP])
	{
		cub->player.position.x += (cos(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, XK_w, X) == EXIT_FAILURE)
			cub->player.position.x -= (cos(cub->player.angle) * 0.10);
		cub->player.position.y += (sin(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, XK_w, Y) == EXIT_FAILURE)
			cub->player.position.y -= (sin(cub->player.angle) * 0.10);
	}
	if (cub->hook[DOWN])
	{
		cub->player.position.x -= (cos(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, XK_s, X) == EXIT_FAILURE)
			cub->player.position.x += (cos(cub->player.angle) * 0.10);
		cub->player.position.y -= (sin(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, XK_s, Y) == EXIT_FAILURE)
			cub->player.position.y += (sin(cub->player.angle) * 0.10);
	}
}

static void	ft_move_east_west(t_cub3d *cub)
{
	if (cub->hook[LEFT])
	{
		cub->player.position.x += (sin(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, XK_a, X) == EXIT_FAILURE)
			cub->player.position.x -= (sin(cub->player.angle) * 0.10);
		cub->player.position.y -= (cos(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, XK_a, Y) == EXIT_FAILURE)
			cub->player.position.y += (cos(cub->player.angle) * 0.10);
	}
	if (cub->hook[RIGHT])
	{
		cub->player.position.x -= (sin(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, XK_d, X) == EXIT_FAILURE)
			cub->player.position.x += (sin(cub->player.angle) * 0.10);
		cub->player.position.y += (cos(cub->player.angle) * 0.10);
		init_hitbox_player(cub);
		if (ft_hitbox(cub, XK_d, Y) == EXIT_FAILURE)
			cub->player.position.y -= (cos(cub->player.angle) * 0.10);
	}
}

static void	ft_angle_direction(t_cub3d *cub)
{
	if (cub->hook[R_LEFT])
		cub->player.angle -= 0.05;
	if (cub->hook[R_RIGHT])
		cub->player.angle += 0.05;
}
