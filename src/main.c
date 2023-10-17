/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/17 18:56:31 by eguelin          ###   ########lyon.fr   */
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
// int	main(int argc, char **argv)
// {
// 	char	**file;

// 	(void)argc;
// 	file = ft_open_file(argv[1]);
// 	ft_printf_tab(file);
// 	ft_free_tab(file);
// 	return (0);
// }

// int	main(int argc, char **argv, char **env)
// {
// 	t_cub3d	cub;
// 	char	**file;

// 	(void)argc;
// 	(void)env;
// 	cub.map = NULL;
// 	file = ft_open_file(argv[1]);
// 	ft_printf_tab(file);
// 	ft_get_map(&cub, file);
// 	ft_printf_tab(cub.map);
// 	ft_free_tab(file);
// 	// printf("x = %lf, y = %lf\n", cub.player.x, cub.player.y);
// 	ft_exit(&cub, NULL, EXIT_SUCCESS);
// 	return (0);
// }

int	main(int argc, char **argv, char **env)
{
	t_cub3d	cub;

	(void)argc;
	(void)env;
	ft_init_cub3d(&cub);
	ft_parser(&cub, argv);
	ft_printf_tab(cub.map);
	printf("x = %lf, y = %lf\n", cub.player.position.x, cub.player.position.y);
	ft_exit(&cub, NULL, EXIT_SUCCESS);
	return (0);
}
