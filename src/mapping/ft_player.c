/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:54:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/19 11:24:27 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_north_south(t_cub3d *cub, int keycode)
{
	float	x;
	float	y;
	
	if (keycode == KEY_W)
	{
		y = cub->player.position.y + (sin(cub->player.angle) * 0.20);
		if (cub->map[(int)y][(int)cub->player.position.x] != '1')
			cub->player.position.y = y;
		x = cub->player.position.x - (cos(cub->player.angle) * 0.20);
		if (cub->map[(int)cub->player.position.y][(int)x] != '1')
			cub->player.position.x = x;
	}
	else if (keycode == KEY_S)
	{
		y = cub->player.position.y - (sin(cub->player.angle) * 0.20);
		if (cub->map[(int)y][(int)cub->player.position.x] != '1')
			cub->player.position.y = y;
		x = cub->player.position.x + (cos(cub->player.angle) * 0.20);
		if (cub->map[(int)cub->player.position.y][(int)x] != '1')
			cub->player.position.x = x;
	}
}

void	ft_move_east_west(t_cub3d *cub, int keycode)
{
	float	x;
	float	y;
	
	if (keycode == KEY_A)
	{
		y = cub->player.position.y - (cos(cub->player.angle) * 0.20);
		if (cub->map[(int)y][(int)cub->player.position.x] != '1')
			cub->player.position.y = y;
		x = cub->player.position.x + (sin(cub->player.angle) * 0.20);
		if (cub->map[(int)cub->player.position.y][(int)x] != '1')
			cub->player.position.x = x;
	}
	else if (keycode == KEY_D)
	{
		y = cub->player.position.y + (cos(cub->player.angle) * 0.20);
		if (cub->map[(int)y][(int)cub->player.position.x] != '1')
			cub->player.position.y = y;
		x = cub->player.position.x - (sin(cub->player.angle) * 0.20);
		if (cub->map[(int)cub->player.position.y][(int)x] != '1')
			cub->player.position.x = x;
	}
}

void	ft_angle_direction(t_cub3d *cub, int keycode)
{
	if (keycode == 65361)
		cub->player.angle -= 0.1;
	else if (keycode == 65363)
		cub->player.angle += 0.1;
}
