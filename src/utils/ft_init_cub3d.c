/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/18 11:35:46 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_cub3d(t_cub3d	*cub)
{
	int	i;
	
	cub->map = NULL;
	i = 0;
	while (i < 4)
	{
		cub->texture[i].img = NULL;
		i++;
	}
}
