/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:10:33 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/31 16:14:17 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	refresh_image(t_cub3d *cub)
{
	ft_visual_field(cub);
	ft_clear_image(cub->minimap[MINIMAP]);
	ft_put_image_to_image(cub->minimap[MINIMAP], cub->minimap[WALL], \
	154.5 - cub->player.position.x * 17, 104.5 - cub->player.position.y * 17);
	ft_put_image_to_image(cub->minimap[MINIMAP], \
	cub->minimap[PLAYER], 150, 100);
	ft_put_image_to_image(cub->windows, cub->minimap[BORDER], 10, 10);
	ft_put_image_to_image(cub->windows, cub->minimap[MINIMAP], 14, 14);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows, 0, 0);
}

static int	ft_handle_keypress(int keycode, t_cub3d *cub)
{
	if (keycode == XK_Escape)
		ft_exit(cub, NULL, EXIT_SUCCESS);
	else if (keycode == XK_W || keycode == XK_S)
		ft_move_north_south(cub, keycode);
	else if (keycode == XK_A || keycode == XK_D)
		ft_move_east_west(cub, keycode);
	else if (keycode == XK_Left || keycode == XK_Right)
		ft_angle_direction(cub, keycode);
	refresh_image(cub);
	return (EXIT_SUCCESS);
}

static void	set_minimap(t_cub3d *cub)
{
	cub->minimap[WALL] = mlx_new_image(cub->mlx, cub->map_width * 17, \
	cub->map_height * 17);
	if (!cub->minimap[WALL])
		ft_exit(cub, NULL, IMG_ERROR);
	cub->minimap[MINIMAP] = mlx_new_image(cub->mlx, 300, 200);
	if (!cub->minimap[MINIMAP])
		ft_exit(cub, NULL, IMG_ERROR);
	set_miniborder_img(cub, 207, 307);
	set_minimap_img(cub, cub->map);
	set_player_img(cub, 8);
	ft_put_image_to_image(cub->minimap[MINIMAP], cub->minimap[WALL], \
	154.5 - cub->player.position.x * 17, 104.5 - cub->player.position.y * 17);
	ft_put_image_to_image(cub->minimap[MINIMAP], cub->minimap[PLAYER], \
	150, 100);
	ft_put_image_to_image(cub->windows, cub->minimap[BORDER], 10, 10);
	ft_put_image_to_image(cub->windows, cub->minimap[MINIMAP], 14, 14);
}

void	cub3d_manager(t_cub3d *cub)
{
	init_hitbox_player(cub);
	cub->resize_len = 1;
	mlx_hook(cub->mlx_win, 2, 1L << 0, ft_handle_keypress, cub);
	mlx_hook(cub->mlx_win, 17, 0, ft_close_win, cub);
	ft_visual_field(cub);
	set_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows, 0, 0);
	mlx_loop(cub->mlx);
}
