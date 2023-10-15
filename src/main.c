/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/15 15:52:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_printf_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

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
	t_cub3d	cub;

	cub.mlx = mlx_init();
	cub.f_colors = -1;
	cub.c_colors = -1;
	if (check_init(argc, env) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_parser(&cub, argv);
	ft_printf_tab(cub.map);
	printf("x = %lf, y = %lf\n", cub.player.x, cub.player.y);
	ft_printf_fd(2, "Fcolors : %d\n", cub.f_colors);
	ft_printf_fd(2, "Ccolors : %d\n", cub.c_colors);
	ft_exit(&cub, NULL, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
