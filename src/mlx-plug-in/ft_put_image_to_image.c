/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:33:00 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/19 19:23:02 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_image_to_image(t_img *img_1, t_img *img_2, int x, int y)
{
	int		*data;
	int		i;
	int		j;
	int 	start;

	i = 0;
	start = 0;
	if (y < 0)
		i = -y;
	if (x < 0)
		start = -x;
	while (i < (img_1->height - y) && i < img_2->height)
	{
		j = start;
		data = ((int *)img_1->data) + (img_1->width * (y + i) + x);
		while (j < (img_1->width - x) && j < img_2->width)
		{
			data[j] = ((int *)img_2->data)[i * img_2->width + j];
			j++;
		}
		i++;
	}
}
