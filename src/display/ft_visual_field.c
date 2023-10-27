/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:20:54 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/27 19:21:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_visual_field(t_cub3d *cub)
{
	int		i;
	int		j;
	t_point	impact;
	double	distance;

	i = 0;
	j = 0;
	while (i < LENGTH)
	{
		if (i < LENGTH >> 1)
			distance = ft_ray_casting(cub, -cub->angle[j++], &impact);
		else if (i == LENGTH >> 1 && LENGTH & 1)
			distance = ft_ray_casting(cub, -cub->angle[j], &impact);
		else
			distance = ft_ray_casting(cub, cub->angle[j--], &impact);
		printf("x = %lf y = %lf d = %lf\n", impact.x, impact.y, distance);
		i++;
	}
}
