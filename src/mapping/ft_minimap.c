/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/18 14:26:31 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_element(t_cub3d *cub, float x, float y, int size)
{
	int	i;
	int	j;

	x = (x) * 17;
	y = (y) * 17;
	i = -1;
	while (++i <= size)
	{
		j = -1;
		while (++j <= size)
		{
			my_mlx_pixel_put(&cub->minimap_img, x, y, 0xFFFFFF);
			y++;
		}
		y = (y - size - 1);
		x++;
	}
}
static void	get_minimap_img(t_cub3d *cub, char **map)
{
	int	x;
	int	y;

	y = -1;
	cub->minimap_img.img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->minimap_img.addr = mlx_get_data_addr(cub->minimap_img.img, \
	&cub->minimap_img.bits_per_pixel, &cub->minimap_img.line_length, \
	&cub->minimap_img.endian);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == '1')
				ft_put_element(cub, x, y, 15);
	}
}

static void	get_player_img(t_cub3d *cub, int size)
{
	int	x;
	int	y;

	cub->player_img.img = mlx_new_image(cub->mlx, size, size);
	cub->player_img.addr = mlx_get_data_addr(cub->player_img.img, \
	&cub->player_img.bits_per_pixel, &cub->player_img.line_length, \
	&cub->player_img.endian);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(&cub->player_img, x, y, 0xFFF000);
			x++;
		}
		y++;
	}
}

void	ft_put_img_to_img(t_cub3d *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->minimap_img.img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->player_img.img, (cub->player.position.x * 17) - 4, (cub->player.position.y * 17) - 4);
}

void	ft_minimap(t_cub3d *cub, char **map)
{
	get_minimap_img(cub, map);
	get_player_img(cub, 7);
	ft_put_img_to_img(cub);
}

