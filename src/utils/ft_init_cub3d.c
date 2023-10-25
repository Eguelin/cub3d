/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/23 12:21:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_cub3d(t_cub3d	*cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_exit(NULL, NULL, MALLOC_ERROR);
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
}
