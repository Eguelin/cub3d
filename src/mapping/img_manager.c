/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/19 22:25:58 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
void	ft_resize_img(t_cub3d *cub, t_image *img, int len)
{
	//int		*start;
	int		x;
	int		y;
	int		src_x;
	int		src_y;
	int		dest_offset;
	int		src_offset;
	t_image	new_img;

	new_img.img = mlx_new_image(cub->mlx, len, len);
	new_img.addr = mlx_get_data_addr(new_img.img, \
	&new_img.bits_per_pixel, &new_img.line_length, \
	&new_img.endian);
	new_img.height = len;
	new_img.width = len;
	y = 0;
	// while (y < new_img.height && y < img->height)
	// {
	// 	start = ((int *)new_img.addr) + (new_img.width * (y + x)+ x);
	// 	x = 0;
	// 	while (x < (new_img.width - x) && x < img->width)
	// 	{
	// 		start[x] = ((int *)img->addr)[y * img->width + x];
	// 		x++;
	// 	}
	// 	y++;
	// }
	while (y < len)
	{
		x = 0;
		while(x < len)
		{
			src_x = (x * img->width / len);
			src_y = (y * img->height / len);
			dest_offset = (y * new_img.line_length) + (x * (new_img.bits_per_pixel / 8));
			src_offset = (src_y * img->line_length) + (src_x * (img->bits_per_pixel / 8));
			new_img.addr[dest_offset] = img->addr[src_offset];
			new_img.addr[dest_offset + 1] = img->addr[src_offset + 1];
			new_img.addr[dest_offset + 2] = img->addr[src_offset + 2];
			x++;
		}
		y++;
	}
	//mlx_destroy_image(cub->mlx, img->img);
	img = &new_img;
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, img->img, 0, 0);
}
void	set_minimap_img(t_cub3d *cub, char **map)
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

void	set_player_img(t_cub3d *cub, int size)
{
	int	x;
	int	y;

	cub->player_img.img = mlx_new_image(cub->mlx, size, size);
	cub->player_img.addr = mlx_get_data_addr(cub->player_img.img, \
	&cub->player_img.bits_per_pixel, &cub->player_img.line_length, \
	&cub->player_img.endian);
	cub->player_img.width = size;
	cub->player_img.height = size; 
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

void	set_window_img(t_cub3d *cub, int width, int height)
{
	cub->windows.img = mlx_new_image(cub->mlx, width, height);
	cub->windows.addr = mlx_get_data_addr(cub->windows.img, \
	&cub->windows.bits_per_pixel, &cub->windows.line_length, \
	&cub->windows.endian);
}



