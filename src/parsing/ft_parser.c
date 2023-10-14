/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:39:14 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/14 19:42:13 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_printf_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
	ft_printf("%s\n", tab[i]);
}

void	ft_parser(t_cub3d *cub, char **argv)
{
	char	**file;

	file = ft_open_file(argv[1]);
	ft_printf_tab(file);
	cub->map = ft_get_map(file);
	if (!cub->map)
		exit (1);
	ft_printf_tab(cub->map);
	ft_printf("%d\n", ft_check_map(cub->map));
	ft_free_split(cub->map);
	ft_free_split(file);
}
