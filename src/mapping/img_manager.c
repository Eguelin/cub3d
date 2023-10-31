/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/26 21:40:37 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_miniborder_img(t_cub3d *cub, int height, int width)
{
	int	x;
	int	y;

	cub->minimap[BORDER] = mlx_new_image(cub->mlx, width, height);
	if (!cub->minimap[BORDER])
		ft_exit(cub, NULL, IMG_ERROR);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y < 3 || y > height - 4 || x < 3 || x > width - 4)
				my_mlx_pixel_put(cub->minimap[BORDER], x, y, 0x808080);
			x++;
		}
		y++;
	}
}

void	set_minimap_img(t_cub3d *cub, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == '1')
				ft_put_element(cub, x, y, 15);
	}
}

void	set_player_img(t_cub3d *cub, int size)
{
	int	x;
	int	y;

	cub->minimap[PLAYER] = mlx_new_image(cub->mlx, size, size);
	if (!cub->minimap[PLAYER])
		ft_exit(cub, NULL, IMG_ERROR);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(cub->minimap[PLAYER], x, y, 0xFFF000);
			x++;
		}
		y++;
	}
}

void	set_window_img(t_cub3d *cub, int width, int height)
{
	cub->windows = mlx_new_image(cub->mlx, width, height);
	if (!cub->windows)
		ft_exit(cub, NULL, IMG_ERROR);
}
