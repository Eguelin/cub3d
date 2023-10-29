/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:55:39 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/29 16:37:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv, char **env)
{
	t_cub3d	cub;

	if (!env)
		ft_exit(NULL, NULL, ENV_ERROR);
	if (argc > 2)
		ft_exit(NULL, NULL, WRONG_FORMAT);
	else if (argc < 2)
		ft_exit(NULL, NULL, WRONG_FORMAT_BIS);
	ft_init(&cub, argv);
	mlx_hook(cub.mlx_win, 17, 0, ft_close_win, &cub);
	ft_visual_field(&cub);
	mlx_loop(cub.mlx);
	return (EXIT_SUCCESS);
}
