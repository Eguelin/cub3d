/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:46:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/11 00:41:50 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_free_pars(t_pars *pars)
{
	if (pars->NO_texture)
		free(pars->NO_texture);
	if (pars->SO_texture)
		free(pars->SO_texture);
	if (pars->WE_texture)
		free(pars->WE_texture);
	if (pars->EA_texture)
		free(pars->EA_texture);
	if (pars->F_colors)
		free(pars->F_colors);
	if (pars->F_colors)
		free(pars->F_colors);
}
void	ft_free_exit(t_pars *pars, int error)
{
	ft_free_pars(pars);
	exit(error);
}