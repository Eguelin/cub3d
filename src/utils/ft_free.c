/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:46:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/14 09:41:18 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_texture(t_cube *cub)
{
	if (cub->texture[0].img)
		mlx_destroy_image(cub->mlx, cub->texture[0].img);
	if (cub->texture[1].img)
		mlx_destroy_image(cub->mlx, cub->texture[1].img);
	if (cub->texture[2].img)
		mlx_destroy_image(cub->mlx, cub->texture[2].img);
	if (cub->texture[3].img)
		mlx_destroy_image(cub->mlx, cub->texture[3].img);
}
