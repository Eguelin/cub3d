/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/28 20:12:39 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_init_struct(t_cub3d	*cub);
static void	ft_calculate_angle_array(t_cub3d *cub);

void	ft_init(t_cub3d	*cub, char **argv)
{
	ft_init_struct(cub);
	ft_parser(cub, argv);
}

static void	ft_init_struct(t_cub3d	*cub)
{
	cub->mlx = NULL;
	cub->mlx_win = NULL;
	cub->windows = NULL;
	cub->minimap_img = NULL;
	cub->player_img = NULL;
	cub->texture[0] = NULL;
	cub->texture[1] = NULL;
	cub->texture[2] = NULL;
	cub->texture[3] = NULL;
	cub->f_colors = -1;
	cub->c_colors = -1;
	cub->map = NULL;
	ft_calculate_angle_array(cub);
}

static void	ft_calculate_angle_array(t_cub3d *cub)
{
	double	opposite;
	double	adjacent;
	int		i;
	int		size;

	i = 0;
	size = (LENGTH >> 1) + 1;
	adjacent = (double)LENGTH / (2 * tan(FOV_2));
	opposite = (double)LENGTH / 2;
	while (i < size)
	{
		cub->angle[i] = atan(opposite / adjacent);
		opposite--;
		i++;
	}
}
