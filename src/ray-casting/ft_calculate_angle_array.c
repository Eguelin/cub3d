/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_angle_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:25:41 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/23 12:30:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_calculate_angle_array(t_cub3d *cub)
{
	double	opposite;
	double	adjacent;
	int		i;
	int		size;

	i = 0;
	size = (LENGTH >> 1) + 1;
	adjacent = (double)LENGTH / (2 * tan(FOV / 2));
	opposite = (double)LENGTH / 2;
	while (i < size)
	{
		cub->angle[i] = atan(opposite / adjacent);
		opposite--;
		i++;
	}
}
