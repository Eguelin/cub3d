/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/19 14:57:28 by acarlott         ###   ########lyon.fr   */
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

int get_pixel_color(t_image *img, int x, int y) 
{
	char *pixel;
	
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return *((unsigned int*)pixel);
}

void set_pixel_color(t_image *img, int x, int y, int color) 
{
	char *pixel;
	// y * img.width + x
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*((unsigned int*)pixel) = color;
}

void	ft_put_img_to_img(t_cub3d *cub, t_image *img, int x, int y)
{
	unsigned int	combined_pixel;
	int				x_start;

	combined_pixel = 0;
	x_start = x;
	while (y < img->height)
	{
		ft_printf("Height = %d\n", img->height);
		ft_printf("Width = %d\n", img->height);
		x = x_start;
		while (x < img->width)
		{
			combined_pixel += get_pixel_color(img, x, y);
			combined_pixel += get_pixel_color(&cub->windows, x, y);
			set_pixel_color(&cub->windows, 0, 0, combined_pixel);
			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, &cub->windows.img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->minimap_img.img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->player_img.img, (cub->player.position.x * 17) - 4, (cub->player.position.y * 17) - 4);
}

void	ft_minimap(t_cub3d *cub, char **map)
{
	get_minimap_img(cub, map);
	get_player_img(cub, 7);
	ft_put_img_to_img(cub, &cub->minimap_img, 0, 0);
	//ft_put_img_to_img(cub, cub->player_img.img, (cub->player.position.x * 17) - 4, (cub->player.position.y * 17) - 4);
}

