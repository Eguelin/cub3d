/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:47:15 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/15 15:00:47 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_cub(t_cub3d *cub);

void	ft_exit(t_cub3d *cub, char const *s, int return_value)
{
	ft_free_cub(cub);
	if (return_value)
		ft_perror(s, return_value);
	exit(return_value);
}

static void	ft_free_cub(t_cub3d *cub)
{
	if (!cub)
		return ;
	ft_free_tab(cub->map);
}
