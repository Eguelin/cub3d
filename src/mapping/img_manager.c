/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/24 16:22:56 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	ft_resize_img(t_cub3d *cub, t_img **img, float len)
{
	int		x;
	int		y;
	int		src_x;
	int		src_y;
	int		dest_offset;
	int		src_offset;
	t_img	*new_img;

	new_img = mlx_new_image(cub->mlx, (len * (*img)->width), (len * (*img)->height));
	y = 0;
	while (y < new_img->height)
	{
		x = 0;
		while(x < new_img->width)
		{
			src_x = x / len;
			src_y = y / len;
			dest_offset = (y * new_img->width) + x;
			src_offset = (src_y * (*img)->width) + src_x;
			((int *)new_img->data)[dest_offset] = ((int *)(*img)->data)[src_offset];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, *img);
	//mlx_put_image_to_window(cub->mlx, cub->mlx_win, img->img, 0, 0);
	*img = new_img;
}

void	set_minimap_img(t_cub3d *cub, char **map)
{
	int	x;
	int	y;

	y = -1;
	//cub->minimap_img = mlx_new_image(cub->mlx, cub->minimap_img->width * 17, cub->minimap_img->height * 17);
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
}
