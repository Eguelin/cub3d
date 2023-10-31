/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/01 00:41:30 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_miniborder_img(t_cub3d *cub, int height, int width);
static void	set_minimap_img(t_cub3d *cub, char **map);
static void	set_player_img(t_cub3d *cub, int size);

void	ft_minimap(t_cub3d *cub)
{
	ft_clear_image(cub->minimap[MINIMAP]);
	ft_put_image_to_image(cub->minimap[MINIMAP], cub->minimap[WALL], \
	154.5 - cub->player.position.x * 17, 104.5 - cub->player.position.y * 17);
	ft_put_image_to_image(cub->minimap[MINIMAP], \
	cub->minimap[PLAYER], 150, 100);
	ft_put_image_to_image(cub->windows, cub->minimap[BORDER], 10, 10);
	ft_put_image_to_image(cub->windows, cub->minimap[MINIMAP], 14, 14);
}

void	set_minimap(t_cub3d *cub)
{
	cub->minimap[WALL] = mlx_new_image(cub->mlx, cub->map_width * 17, \
	cub->map_height * 17);
	if (!cub->minimap[WALL])
		ft_exit(cub, NULL, IMG_ERROR);
	cub->minimap[MINIMAP] = mlx_new_image(cub->mlx, 300, 200);
	if (!cub->minimap[MINIMAP])
		ft_exit(cub, NULL, IMG_ERROR);
	set_miniborder_img(cub, 207, 307);
	set_minimap_img(cub, cub->map);
	set_player_img(cub, 8);
	ft_put_image_to_image(cub->minimap[MINIMAP], cub->minimap[WALL], \
	154.5 - cub->player.position.x * 17, 104.5 - cub->player.position.y * 17);
	ft_put_image_to_image(cub->minimap[MINIMAP], cub->minimap[PLAYER], \
	150, 100);
	ft_put_image_to_image(cub->windows, cub->minimap[BORDER], 10, 10);
	ft_put_image_to_image(cub->windows, cub->minimap[MINIMAP], 14, 14);
}

static void	set_miniborder_img(t_cub3d *cub, int height, int width)
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
				ft_put_pixel_to_image(cub->minimap[BORDER], x, y, 0x808080);
			x++;
		}
		y++;
	}
}

static void	set_minimap_img(t_cub3d *cub, char **map)
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

static void	set_player_img(t_cub3d *cub, int size)
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
			ft_put_pixel_to_image(cub->minimap[PLAYER], x, y, 0xFFF000);
			x++;
		}
		y++;
	}
}
