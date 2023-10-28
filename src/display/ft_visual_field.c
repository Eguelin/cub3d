/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:20:54 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/28 20:28:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_get_texture_ratio(\
int length, t_cub3d *cub, t_point impact, double distance);

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
		if (i < LENGTH_2)
			distance = ft_ray_casting(cub, -cub->angle[j++], &impact);
		else if (i == LENGTH_2 && LENGTH & 1)
			distance = ft_ray_casting(cub, -cub->angle[j], &impact);
		else
			distance = ft_ray_casting(cub, cub->angle[j--], &impact);
		ft_get_texture_ratio(i, cub, impact, distance);
		i++;
	}
}

static void	ft_get_texture_ratio(\
int length, t_cub3d *cub, t_point impact, double distance)
{
	int		i;
	double	ratio;

	i = 0;
	ratio = impact.x - (size_t)impact.x;
	if (!ratio)
	{
		i = 3;
		ratio = impact.y - (size_t)impact.y;
		if (cub->player.position.x > impact.x)
		{
			i = 2;
			ratio = 1 - ratio;
		}
	}
	else if (cub->player.position.y < impact.y)
	{
		i = 1;
		ratio = 1 - ratio;
	}
	printf("x = %lf y = %lf d = %lf\n", impact.x, impact.y, distance);
	printf("i = %d ratio = %lf\n", i, ratio);
	(void)length;
}
