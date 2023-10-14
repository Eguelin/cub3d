/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/14 10:53:57 by acarlott         ###   ########lyon.fr   */
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
	cube_manager(&cub);
	ft_destroy_texture(&cub);
	free(cub.mlx);
	return (EXIT_SUCCESS);
}
