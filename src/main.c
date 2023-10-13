/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/13 01:00:47 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_init(int argc, char **env)
{
	if (!env)
		return (ft_printf_fd(STDERR_FILENO, "empty env !\n"), ENV_ERROR);
	if (argc != 2)
	{
		if (argc > 2)
			return (ft_perror(NULL, WRONG_FORMAT));
		else
			return (ft_perror(NULL, WRONG_FORMAT_BIS));
		return (WRONG_FORMAT);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	t_cube	cub;

	cub.mlx = mlx_init();
	cub.f_colors = -1;
	cub.c_colors = -1;
	if (check_init(argc, env) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (parsing(&cub, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_printf_fd(2, "Fcolors : %d\n", cub.f_colors);
	ft_printf_fd(2, "Ccolors : %d\n", cub.c_colors);
	cube_manager(&cub);
	mlx_destroy_image(cub.mlx, cub.texture[0].img);
	mlx_destroy_image(cub.mlx, cub.texture[1].img);
	mlx_destroy_image(cub.mlx, cub.texture[2].img);
	mlx_destroy_image(cub.mlx, cub.texture[3].img);
	mlx_destroy_display(cub.mlx);
	mlx_destroy_window(cub.mlx, cub.mlx_win);
	free(cub.texture[0].img);
	free(cub.texture[1].img);
	free(cub.texture[2].img);
	free(cub.texture[3].img);
	free(cub.mlx_win);
	free(cub.mlx);
	return (EXIT_SUCCESS);
}
