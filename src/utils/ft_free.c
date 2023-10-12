/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:46:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/12 16:18:47 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_mlx(t_cube *cub)
{
	// int	i;

	// i = 0;
	// if (cub->texture[0].img)
	// {
	// 	while(cub->texture[0].img[i])
	// 		free(cub->texture[0].img[i]);
	// 	free (cub->texture[0].img);
	// }
	// return ;
}

void	ft_free_exit(t_cube *cub, int error)
{
	ft_free_mlx(cub);
	exit(error);
}
