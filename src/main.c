/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/12 19:46:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv, char **env)
{
	char	**file;
	size_t	i;

	(void)argc;
	(void)argv;
	(void)env;
	i = 0;
	file = ft_open_file(argv[1]);
	while (file && file[i])
		ft_printf("%s", file[i++]);
	if (file)
		ft_printf("%s\n", file[i]);
	ft_get_map(file);
	ft_free_split(file);
	return (0);
}
