/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:10:33 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/14 11:30:04 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_close_window(t_cube *cub)
{
	(void)cub;
	//ft_destroy_texture(cub);
	// mlx_destroy_window(cub->mlx, cub->mlx_win);
	// mlx_destroy_display(cub->mlx);
	// free(cub->mlx);
	exit(0);
}

static int ft_handle_keypress(int keycode, t_cube *cub)
{
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == 65307)
		ft_close_window(cub);
	if (keycode == 122)
		ft_player_move(cub, keycode);
	return (EXIT_SUCCESS);
}

void	cube_manager(t_cube *cub)
{
	// int		len;
	// int		width;
	char *mapp[] = {
		"                                   ",
		"         1111111111111111111111111 ",
	    "         1000000000110000000000001 ",
	    "      1111011000001110000000000001 ",
	    "      1111001000000000000000000001 ",
	    " 111111111011000001110000000000001 ",
	    " 100000000011000001110111110111111 ",
	    " 11110111111111011100000010001     ",
	    " 11110111111111011101010010001     ",
	    " 11000000110101011100000010001     ",
	    " 10000000000000000000000000001     ",
	    " 10000000000000001101010010001     ",
	    " 11000001110101011111011110N0111   ",
	    "   111101111110101101111010001     ",
	    "      11111 1111111111 1111111     ",
		"                                   ",
		NULL
};
	cub->map = mapp;
	// len = 32;
	// width = 32;
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, 860, 620, "Cub3d");
	ft_minimap(cub, cub->map);
	mlx_key_hook(cub->mlx_win, ft_handle_keypress, cub);
	// mlx_hook(cub->mlx_win, 2, 0, ft_handle_keypress, &cub);
	mlx_hook(cub->mlx_win, 17, 0, ft_close_window, &cub);
	mlx_loop(cub->mlx);
}
