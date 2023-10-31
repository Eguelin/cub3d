/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:49:34 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/01 00:41:55 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_border(t_cub3d *cub, float x, float y, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= size)
	{
		j = -1;
		while (++j <= size)
		{
			ft_put_pixel_to_image(cub->minimap[BORDER], x, y, 0xF00000);
			y++;
		}
		y = (y - size - 1);
		x++;
	}
}

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
			ft_put_pixel_to_image(cub->minimap[WALL], x, y, 0xFFFFFF);
			y++;
		}
		y = (y - size - 1);
		x++;
	}
}
