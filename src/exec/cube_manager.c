/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:10:33 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/11 15:21:48 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_close_window(void)
{
	exit(0);
}

void	cube_manager(t_cube *cub)
{
	int		len;
	int		width;

	len = 10;
	width = 10;
	cub->x = 0;
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, (len * 64), (width * 64), "Cub3d");
	mlx_hook(cub->mlx_win, 17, 0, ft_close_window, &cub);
	mlx_loop(cub->mlx);
}
