/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:33:00 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/20 13:31:14 by eguelin          ###   ########lyon.fr   */
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
