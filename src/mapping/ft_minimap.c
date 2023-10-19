/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/19 17:02:37 by eguelin          ###   ########lyon.fr   */
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
	cub->minimap_img.img = mlx_new_image(cub->mlx, cub->minimap_img.width * 17, cub->minimap_img.height * 17);
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

void	ft_put_img_to_img(t_img *img_1, t_img *img_2, int x, int y)
{
	int		*start;
	int		i;
	int		j;

	i = 0;
	while (i < (img_1->height - y) && i < img_2->height)
	{
		j = 0;
		start = ((int *)img_1->data) + (img_1->width * (y + i)+ x);
		while (j < (img_1->width - x) && j < img_2->width)
		{
			start[j] = ((int *)img_2->data)[i * img_2->width + j];
			j++;
		}
		i++;
	}
}

void	ft_minimap(t_cub3d *cub, char **map)
{
	get_minimap_img(cub, map);
	get_player_img(cub, 7);
	ft_put_img_to_img(cub->windows.img, cub->minimap_img.img, 0, 0);
	ft_put_img_to_img(cub->windows.img, cub->player_img.img, (cub->player.position.x * 17) - 4, (cub->player.position.y * 17) - 4);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows.img, 0, 0);
}

