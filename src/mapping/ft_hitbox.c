/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hitbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:13:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/30 16:57:19 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_hitbox_player(t_cub3d *cub)
{
	cub->player.hitbox[TOP_L].x = cub->player.position.x - 0.2;
	cub->player.hitbox[TOP_L].y = cub->player.position.y - 0.2;
	cub->player.hitbox[TOP_R].x = cub->player.position.x + 0.2;
	cub->player.hitbox[TOP_R].y = cub->player.position.y - 0.2;
	cub->player.hitbox[BOTTOM_L].x = cub->player.position.x - 0.2;
	cub->player.hitbox[BOTTOM_L].y = cub->player.position.y + 0.2;
	cub->player.hitbox[BOTTOM_R].x = cub->player.position.x + 0.2;
	cub->player.hitbox[BOTTOM_R].y = cub->player.position.y + 0.2;
}

static void	ft_hitbox_move(t_cub3d *cub, t_point *direction, int keycode)
{
	if (keycode == KEY_W)
	{
		direction->y = (sin(cub->player.angle) * 0.20);
		direction->x -= (cos(cub->player.angle) * 0.20);
	}
	else if (keycode == KEY_S)
	{
		direction->y -= (sin(cub->player.angle) * 0.20);
		direction->x = (cos(cub->player.angle) * 0.20);
	}
	else if (keycode == KEY_A)
	{
		direction->y -= (cos(cub->player.angle) * 0.20);
		direction->x = (sin(cub->player.angle) * 0.20);
	}
	else if (keycode == KEY_D)
	{
		direction->y = (cos(cub->player.angle) * 0.20);
		direction->x -= (sin(cub->player.angle) * 0.20);
	}
}

static int	check_hitbox_x(t_cub3d *cub, t_point *direction)
{
	if (cub->map[(int)cub->player.hitbox[TOP_L].y]\
	[(int)cub->player.hitbox[TOP_L].x + (int)direction->x] == '1')
		return (EXIT_FAILURE);
	if (cub->map[(int)cub->player.hitbox[TOP_R].y]\
	[(int)cub->player.hitbox[TOP_R].x + (int)direction->x] == '1')
		return (EXIT_FAILURE);
	if (cub->map[(int)cub->player.hitbox[BOTTOM_L].y]\
	[(int)cub->player.hitbox[BOTTOM_L].x + (int)direction->x] == '1')
		return (EXIT_FAILURE);
	if (cub->map[(int)cub->player.hitbox[BOTTOM_R].y]\
	[(int)cub->player.hitbox[BOTTOM_R].x + (int)direction->x] == '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_hitbox_y(t_cub3d *cub, t_point *direction)
{
	if (cub->map[(int)cub->player.hitbox[TOP_L].y + \
	(int)direction->y][(int)cub->player.hitbox[TOP_L].x] == '1')
		return (EXIT_FAILURE);
	if (cub->map[(int)cub->player.hitbox[TOP_R].y + \
	(int)direction->y][(int)cub->player.hitbox[TOP_R].x] == '1')
		return (EXIT_FAILURE);
	if (cub->map[(int)cub->player.hitbox[BOTTOM_L].y + \
	(int)direction->y][(int)cub->player.hitbox[BOTTOM_L].x] == '1')
		return (EXIT_FAILURE);
	if (cub->map[(int)cub->player.hitbox[BOTTOM_R].y + \
	(int)direction->y][(int)cub->player.hitbox[BOTTOM_R].x] == '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


int	ft_hitbox(t_cub3d *cub, int keycode, int point)
{
	t_point	direction;

	direction.x = 0.0;
	direction.y = 0.0;
	ft_hitbox_move(cub, &direction, keycode);
	if (point == Y)
	{
		if (check_hitbox_y(cub, &direction) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (check_hitbox_x(cub, &direction) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
