/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:46:19 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/11 00:36:10 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

static int	is_sorted(char **file)
{
	int	value;
	int	i;

	i = -1;
	value = 0;
	while (file[++i])
	{
		while (file[i][0] == '\n')
			i++;
		if (!file[i])
			break ;
		if (sorted_condition(file[i], value) == TRUE)
			value++;
		else
			break ;
	}
	if (value != 5)
		return (ft_printf_fd(2, "Error, texture files not sorted\n", FALSE));
	return (TRUE);
}

int	parsing(t_pars *pars, char **argv)
{
	char	**file;
	
	(void)argv;
	file = NULL;
	if (is_sorted(file) == FALSE)
		return (ERROR_SORT);
	if (init_texture(pars, file) == FALSE)
		return (ERROR_TEXTURE);
	return (TRUE);
}
