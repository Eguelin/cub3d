/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:46:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/11 15:41:50 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_cube(t_cube *cub)
{
	(void)cub;
	return ;
}

void	ft_free_exit(t_cube *cub, int error)
{
	ft_free_cube(cub);
	exit(error);
}
