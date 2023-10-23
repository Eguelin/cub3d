/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/23 19:45:33 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_image_to_image(t_img *img_1, t_img *img_2, int x, int y)
{
	int	*data_1;
	int	*data_2;
	int	i;
	int	j;

	i = 0;
	if (y < 0)
		i = -y;
	data_1 = ((int *)img_1->data) + (img_1->width * (y + i) + x);
	data_2 = ((int *)img_2->data) + (img_2->width * i);
	while (i < (img_1->height - y) && i < img_2->height)
	{
		if (x < 0)
			j = -x;
		else
			j = 0;
		while (j < (img_1->width - x) && j < img_2->width)
		{
			data_1[j] = data_2[j];
			j++;
		}
		data_1 += img_1->width;
		data_2 += img_2->width;
		i++;
	}
}

void	ft_resize_img(t_cub3d *cub, t_image *img, float len)
{
	int		x;
	int		y;
	int		src_x;
	int		src_y;
	int		dest_offset;
	int		src_offset;
	t_image	new_img;

	new_img.img = mlx_new_image(cub->mlx, (len * img->width), (len * img->height));
	new_img.addr = mlx_get_data_addr(new_img.img, 
	&new_img.bits_per_pixel, &new_img.line_length, 
	&new_img.endian);
	new_img.height = (int)(len * img->height);
	new_img.width = (int)(len * img->width);
	y = 0;
	while (y < new_img.height)
	{
		x = 0;
		while(x < new_img.width)
		{
			src_x = x / len;
			src_y = y / len;
			dest_offset = (y * new_img.width) + x;
			src_offset = (src_y * img->width) + src_x;
			((int *)new_img.addr)[dest_offset] = ((int *)img->addr)[src_offset];
			x++;
		}
		y++;
	}
	//mlx_destroy_image(cub->mlx, img->img);
	//mlx_put_image_to_window(cub->mlx, cub->mlx_win, img->img, 0, 0);
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
	cub->minimap_img.width *= 17;
	cub->minimap_img.height *= 17; 
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



