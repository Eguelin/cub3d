/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:33:00 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/21 17:58:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int		*data;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	data = ((int *)img->data) + ((img->width * y) + x);
	*data = color;
}
