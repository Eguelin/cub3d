/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/27 13:36:53 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_cub3d(t_cub3d	*cub)
{
	int	i;

	cub->resize_len = 1;
	cub->f_colors = -1;
	cub->c_colors = -1;
	cub->mlx_win = NULL;
	cub->windows = NULL;
	cub->map = NULL;
	i = 0;
	while (i < 4)
	{
		cub->texture[i] = NULL;
		cub->minimap[i] = NULL;
		i++;
	}
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_exit(cub, NULL, MALLOC_ERROR);
}
