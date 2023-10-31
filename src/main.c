/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:55:39 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/31 15:51:37 by eguelin          ###   ########lyon.fr   */
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
	cub3d_manager(&cub);
	return (EXIT_SUCCESS);
}
