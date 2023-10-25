/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:10:33 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/17 17:43:09 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int ft_handle_keypress(int keycode, t_cub3d *cub)
{
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		ft_exit(cub, NULL, EXIT_SUCCESS);
	else if (keycode == KEY_W || keycode == KEY_S)
		ft_move_north_south(cub, keycode);
	else if (keycode == KEY_A || keycode == KEY_D)
		ft_move_east_west(cub, keycode);
	else if (keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
		ft_angle_direction(cub, keycode);
	ft_put_image_to_image(cub->windows, cub->border, 0, 0);
	ft_put_image_to_image(cub->windows, cub->minimap_img, 4, 4);
	ft_put_image_to_image(cub->windows, cub->player_img, \
	(cub->player.position.x * 17  + 2) * cub->resize_len, (cub->player.position.y * 17 + 2) * cub->resize_len);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows, 0, 0);
	return (EXIT_SUCCESS);
}

void	cub3d_manager(t_cub3d *cub)
{
	//resize_len est notre multiplicateur a definir pour le resize des images a l'aide de la distance 
	cub->resize_len = 0.9;
	cub->mlx_win = mlx_new_window(cub->mlx, 860, 620, "Cub3d");
	mlx_hook(cub->mlx_win, 2, 1L<<0, ft_handle_keypress, cub);
	mlx_hook(cub->mlx_win, 17, 0, ft_close_win, cub);
	set_window_img(cub, 1920, 1080);
	set_minimap_img(cub, cub->map);
	set_player_img(cub, 4);
	ft_resize_img(cub, &cub->minimap_img, cub->resize_len);
	set_miniborder_img(cub);
	ft_resize_img(cub, &cub->player_img, cub->resize_len);
	ft_put_image_to_image(cub->windows, cub->border, 0, 0);
	ft_put_image_to_image(cub->windows, cub->minimap_img, 4, 4);
	ft_put_image_to_image(cub->windows, cub->player_img, \
	(cub->player.position.x * 17  + 2) * cub->resize_len, (cub->player.position.y * 17 + 2) * cub->resize_len);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows, 0, 0);
	mlx_loop(cub->mlx);
}
