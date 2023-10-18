/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:48:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/18 15:54:59 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_win(t_cub3d *cub)
{
	ft_exit(cub, NULL, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
