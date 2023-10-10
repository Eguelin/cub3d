/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/10 17:41:58 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_init(int argc, char **argv, char **env)
{
	if (!env)
		return (EMPTY_ENV, ft_printf_fd(STDERR_FILENO, "empty env !\n"));
	if (argv != 1) 
	{
		ft_printf_fd(STDERR_FILENO, "wrong number of parameters, 1 expected\n");
		return (ERROR_PARAM);
	}
	return (SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	t_cube	cube;
	
	i = check_init(argc, argv, env);
	if (i != SUCCESS)
		return (i);
	i = parsing(&cube, argc, argv);
	if (i != SUCCESS)
		return (i);
	return (EXIT_SUCCESS);
}
