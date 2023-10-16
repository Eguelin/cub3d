/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:39:14 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/16 18:55:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parser(t_cub3d *cub, char **argv)
{
	char	**file;

	file = ft_open_file(argv[1]);
	ft_get_map(cub, file);
	ft_free_tab(file);
	ft_check_map(cub);
}
