/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:35:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/01 00:44:05 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	refresh_image(t_cub3d *cub);

void	ft_display(t_cub3d *cub)
{
	ft_visual(cub);
	set_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows, 0, 0);
	mlx_hook(cub->mlx_win, 2, 1L << 0, ft_key_press, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, ft_key_release, cub);
	mlx_hook(cub->mlx_win, 17, 0, ft_close_win, cub);
	mlx_loop_hook(cub->mlx, refresh_image, cub);
	mlx_loop(cub->mlx);
}

static int	refresh_image(t_cub3d *cub)
{
	ft_move(cub);
	ft_visual(cub);
	ft_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows, 0, 0);
	return (0);
}
