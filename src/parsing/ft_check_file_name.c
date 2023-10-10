/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:00:38 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/10 20:02:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file_name(char *name)
{
	if (ft_strncmp(name + ft_strlen(name) - 4, ".cub", 5))
	{
		ft_perror(name, WRONG_ARGUMENTS);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
