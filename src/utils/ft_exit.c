/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:47:15 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/18 11:38:48 by acarlott         ###   ########lyon.fr   */
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

void	ft_destroy_texture(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->texture[i].img)
			mlx_destroy_image(cub->mlx, cub->texture[i].img);
		i++;
	}
}

static void	ft_free_cub(t_cub3d *cub)
{
	if (!cub)
		return ;
	ft_free_tab(cub->map);
	ft_destroy_texture(cub);
	// if (cub->windows)
	// 	mlx_destroy_window(cub->mlx, cub->mlx_win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->mlx);
}
