/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:47:15 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/26 01:00:22 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_free_cub(t_cub3d *cub);
static void	ft_destroy_texture(t_cub3d *cub);

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
	ft_destroy_texture(cub);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->mlx);
}

static void	ft_destroy_texture(t_cub3d *cub)
{
	int	i;

	i = 0;
	if (cub->windows)
		mlx_destroy_image(cub->mlx, cub->windows);
	if (cub->minimap_img)
		mlx_destroy_image(cub->mlx, cub->minimap_img);
	if (cub->border)
		mlx_destroy_image(cub->mlx, cub->border);
	if (cub->player_img)
		mlx_destroy_image(cub->mlx, cub->player_img);
	while (i < 4)
	{
		if (cub->texture[i])
			mlx_destroy_image(cub->mlx, cub->texture[i]);
		i++;
	}
}
