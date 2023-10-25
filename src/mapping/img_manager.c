/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/26 00:58:12 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_miniborder_img(t_cub3d *cub)
{
	int	x;
	int	y;

	cub->border = mlx_new_image(cub->mlx, (cub->minimap_img->width + 8), (cub->minimap_img->height + 8));
	if (!cub->border)
		ft_exit(cub, NULL, IMG_ERROR);
	y = 0;
	while (y < cub->border->height)
	{
		x = 0;
		while (x < cub->border->width)
		{
			if (y < 3 || y > cub->border->height - 4 || x < 3 || x > cub->border->width - 4)
				my_mlx_pixel_put(cub->border, x, y, 0x808080);
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

	cub->player_img = mlx_new_image(cub->mlx, size, size);
	if (!cub->player_img)
		ft_exit(cub, NULL, IMG_ERROR);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(cub->player_img, x, y, 0xFFF000);
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
