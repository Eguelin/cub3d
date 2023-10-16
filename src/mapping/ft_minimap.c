/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/16 21:36:13 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_element(t_cube *cub, float x, float y, int size)
{
	int	i;
	int	j;

	x = (x + 1) * 17;
	y = (y + 1) * 17;
	if (size == 8)
	{
		x += (0.25 * 17);
		y += (0.25 * 17);
	}
	i = -1;
	while (++i <= size)
	{
		j = -1;
		while (++j <= size)
		{
			if (size == 8)
				my_mlx_pixel_put(&cub->windows, x, y, 0xFFF000);
			else
				my_mlx_pixel_put(&cub->windows, x, y, 0xFFFFFF);
			y++;
		}
		y = (y - size - 1);
		x++;
	}
}

static void	init_player_pos(t_cube *cub, char **map)
{
	int	x;
	int	y;
	
	y = -1;
	cub->player.angle = 0.0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' \
			|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				cub->player.y_start = (float)y;
				cub->player.x_start = (float)x;
				printf("cub->player.y_start = %f\n", cub->player.y_start);
				printf("cub->player.x_start = %f\n", cub->player.x_start);
				break ;
			}
		}
	}
}

void	set_view_minimap(t_cube *cub, char **map)
{
	int	x;
	int	y;

	y = -1;
	cub->windows.img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->windows.addr = mlx_get_data_addr(cub->windows.img, \
	&cub->windows.bits_per_pixel, &cub->windows.line_length, \
	&cub->windows.endian);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				ft_put_element(cub, x, y, 15);
			else if (x == round(cub->player.x_start) && \
			y == round(cub->player.y_start))
				ft_put_element(cub, cub->player.x_start, \
				cub->player.y_start, 8);
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows.img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->windows.img);
}

void	ft_minimap(t_cube *cub, char **map)
{
	init_player_pos(cub, map);
	set_view_minimap(cub, map);
}
