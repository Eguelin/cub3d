/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:49:34 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/19 18:58:39 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_element(t_cub3d *cub, float x, float y, int size)
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

void	my_mlx_pixel_put(t_image *txr, int x, int y, int color)
{
	char	*dst;

	dst = txr->addr + (y * txr->line_length + \
	x * (txr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
