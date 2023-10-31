/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:37:23 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/01 00:38:39 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_press(int keycode, t_cub3d *cub)
{
	if (keycode == XK_Escape)
		ft_exit(cub, NULL, EXIT_SUCCESS);
	if (keycode == XK_w)
		cub->hook[UP] = 1;
	if (keycode == XK_s)
		cub->hook[DOWN] = 1;
	if (keycode == XK_a)
		cub->hook[LEFT] = 1;
	if (keycode == XK_d)
		cub->hook[RIGHT] = 1;
	if (keycode == XK_Left)
		cub->hook[R_LEFT] = 1;
	if (keycode == XK_Right)
		cub->hook[R_RIGHT] = 1;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int keycode, t_cub3d *cub)
{
	if (keycode == XK_w)
		cub->hook[UP] = 0;
	if (keycode == XK_s)
		cub->hook[DOWN] = 0;
	if (keycode == XK_a)
		cub->hook[LEFT] = 0;
	if (keycode == XK_d)
		cub->hook[RIGHT] = 0;
	if (keycode == XK_Left)
		cub->hook[R_LEFT] = 0;
	if (keycode == XK_Right)
		cub->hook[R_RIGHT] = 0;
	return (EXIT_SUCCESS);
}
