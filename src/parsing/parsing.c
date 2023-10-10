/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:46:19 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/10 17:53:41 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	sorted_condition(char *file, int value)
{
	if (value == 0 && ft_strncmp(file, "NO", 2))
		return (TRUE);
	else if (value == 1 && ft_strncmp(file, "SO", 2))
		return (TRUE);
	else if (value == 2 && ft_strncmp(file, "WE", 2))
		return (TRUE);
	else if (value == 3 && ft_strncmp(file, "EA", 2))
		return (TRUE);
	else if (value == 4 && ft_strncmp(file, "F", 1))
		return (TRUE);
	else if (value == 5 && ft_strncmp(file, "C", 1))
		return (TRUE);
	return (FALSE);
}

static int	is_sorted(t_cube *cube, char **file)
{
	int	value;
	int	i;
	int	j;

	i = -1;
	value = 0;
	while (file[++i])
	{
		while (file[i][0] == '\n')
			i++;
		if (sorted_condition(file[i], value) == TRUE)
			value++;
		else
			break ;
	}
	if (value != 5)
		return (FALSE, ft_printf_fd(2, "Error, texture files not sorted\n"));
	return (TRUE);
}

int	parsing(t_cube *cube, int argc, char **argv) 
{
	if (is_sorted(cube, file) == FALSE)
		return (ERROR_SORT);
	if (init_texture(cube, file) == FALSE)
		return (ERROR_TEXTURE);
}
