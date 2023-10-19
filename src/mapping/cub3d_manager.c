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

#include "cub3d.h"

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
	ft_put_img_to_img(cub->windows.img, cub->minimap_img.img, 0, 0);
	ft_put_img_to_img(cub->windows.img, cub->player_img.img, (cub->player.position.x * 17) - 4, (cub->player.position.y * 17) - 4);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows.img, 0, 0);
	return (EXIT_SUCCESS);
}

void	cub3d_manager(t_cub3d *cub)
{
	cub->windows.img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->windows.addr = mlx_get_data_addr(cub->windows.img, \
	&cub->windows.bits_per_pixel, &cub->windows.line_length, \
	&cub->windows.endian);
	cub->mlx_win = mlx_new_window(cub->mlx, 1920, 1080, "Cub3d");
	mlx_hook(cub->mlx_win, 2, 1L<<0, ft_handle_keypress, cub);
	mlx_hook(cub->mlx_win, 17, 0, ft_close_win, cub);
	ft_minimap(cub, cub->map);
	mlx_loop(cub->mlx);
}
