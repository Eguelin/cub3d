/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:54:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/14 11:46:54 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_cube *cub, float start, float end, int xy)
{
	if (xy == NORTH || xy == SOUTH)
	{
		while (round(start) <= round(end))
		{
			mlx_pixel_put(cub->mlx, cub->mlx_win, start, cub->player.x_start, 0xFFF000);
			start += 1;
		}
	}
}
void	ft_remove_pixel(t_cube *cub, float start, float end, int xy)
{
	if (xy == NORTH || xy == SOUTH)
	{
		while (round(start) <= round(end))
		{
			mlx_pixel_put(cub->mlx, cub->mlx_win, cub->player.x_start, start, 0);
			start += 1;
		}
	}
}

void	ft_print_player(t_cube *cub, int direction)
{
	if (direction == NORTH)
	{
		ft_remove_pixel(cub, cub->player.y_start, \
		cub->player.y_end, NORTH);
		cub->player.x_start -= 10;
		cub->player.x_end -= 10;
		ft_put_pixel(cub, cub->player.y_start, \
		cub->player.y_end, NORTH);
	}
}

void	ft_player_move(t_cube *cub, int keycode)
{
	printf("x_start : %f\n", cub->player.x_start);
	printf("y_start : %f\n", cub->player.y_start);
	printf("x_end : %f\n", cub->player.x_end);
	printf("y_end : %f\n", cub->player.y_end);
	if (keycode == 122)
		ft_print_player(cub, NORTH);
}