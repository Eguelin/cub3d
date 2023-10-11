/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/11 15:39:21 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_init(int argc, char **env)
{
	if (!env)
		return (ft_printf_fd(STDERR_FILENO, "empty env !\n"), EMPTY_ENV);
	if (argc != 1)
	{
		ft_printf_fd(STDERR_FILENO, "wrong number of parameters, 1 expected\n");
		return (ERROR_PARAM);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	t_cube	cub;

	i = check_init(argc, env);
	if (i != EXIT_SUCCESS)
		return (i);
	(void)argv;
	parsing(&cub, argv);
	if (i != EXIT_SUCCESS)
		return (i);
	cube_manager(&cub);
	return (EXIT_SUCCESS);
}
