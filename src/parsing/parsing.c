/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:46:19 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/12 11:33:48 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	sorted_condition(char *file, int value)
{
	if (value == 0 && ft_strncmp(file, "NO", 2))
		return (EXIT_SUCCESS);
	else if (value == 1 && ft_strncmp(file, "SO", 2))
		return (EXIT_SUCCESS);
	else if (value == 2 && ft_strncmp(file, "WE", 2))
		return (EXIT_SUCCESS);
	else if (value == 3 && ft_strncmp(file, "EA", 2))
		return (EXIT_SUCCESS);
	else if (value == 4 && ft_strncmp(file, "F", 1))
		return (EXIT_SUCCESS);
	else if (value == 5 && ft_strncmp(file, "C", 1))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	is_sorted(char **file)
{
	int	value;
	int	i;

	i = -1;
	value = 0;
	while (file[++i] && value != 5)
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
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parsing(t_cube *cub, char **argv)
{
	char	**file;
	int		check;

	file = ft_open_file(argv[1]);
	if (!file)
		return (EXIT_FAILURE);
	if (is_sorted(file) == EXIT_FAILURE)
		return (ft_free_split(file), ft_perror(NULL, SORT_ERROR));
	check = init_texture(cub, file);
	if (check == EXIT_FAILURE)
	ft_free_split(file);
	return (EXIT_SUCCESS);
}
