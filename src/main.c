/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/15 14:52:46 by eguelin          ###   ########lyon.fr   */
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

int	main(int argc, char **argv, char **env)
{
	t_cub3d	cub;

	(void)argc;
	(void)env;
	ft_parser(&cub, argv);
	ft_printf_tab(cub.map);
	printf("x = %lf, y = %lf\n", cub.player.x, cub.player.y);
	ft_exit(&cub, NULL, EXIT_SUCCESS);
	return (0);
}
