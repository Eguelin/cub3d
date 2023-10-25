/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:48:13 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/26 00:48:31 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_resize_img(t_cub3d *cub, t_img **img, float len)
{
	int		x;
	int		y;
	int		dest_offset;
	int		src_offset;
	t_img	*new_img;

	new_img = mlx_new_image(cub->mlx, (len * (*img)->width), (len * (*img)->height));
	if (!new_img)
		ft_exit(cub, NULL, IMG_ERROR);
	y = -1;
	while (++y < new_img->height)
	{
		x = 0;
		while(x < new_img->width)
		{
			dest_offset = (y * new_img->width) + x;
			src_offset = ((int)(y / len) * (*img)->width) + (x / len);
			((int *)new_img->data)[dest_offset] = ((int *)(*img)->data)[src_offset];
			x++;
		}
	}
	mlx_destroy_image(cub->mlx, *img);
	*img = new_img;
}